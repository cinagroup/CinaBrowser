// Copyright 2023 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/html/json_document.h"

#include "testing/gtest/include/gtest/gtest.h"
#include "third_party/blink/renderer/core/dom/shadow_root.h"
#include "third_party/blink/renderer/core/events/mouse_event.h"
#include "third_party/blink/renderer/core/testing/sim/sim_request.h"
#include "third_party/blink/renderer/core/testing/sim/sim_test.h"

namespace blink {
class JSONDocumentTest : public SimTest {
 public:
  void SetUp() override { SimTest::SetUp(); }

  void LoadResource(const String& json) {
    SimRequest request("https://foobar.com", "application/json");
    LoadURL("https://foobar.com");
    request.Complete(json);
    Compositor().BeginFrame();
  }
  void ClickPrettyPrintCheckbox() {
    GetDocument()
        .documentElement()
        ->QuerySelector(html_names::kDivTag.LocalName())
        ->GetShadowRoot()
        ->QuerySelector(html_names::kInputTag.LocalName())
        ->DispatchSimulatedClick(MouseEvent::Create());
  }
};

TEST_F(JSONDocumentTest, JSONDoc) {
  static const char kJSON[] =
      "{\"menu\":{\"id\":\"file\",\"value\":\"File\",\"popup\":{\"menuitem\":[{"
      "\"value\":\"New\",\"click\":\"CreateNewDoc\"}]},\"itemCount\":3,"
      "\"isShown\":      true}}";
  static const char kFormatted[] =
      "{\n  \"menu\": {\n    \"id\": \"file\",\n    \"value\": \"File\",\n    "
      "\"popup\": {\n      \"menuitem\": [\n        {\n          \"value\": "
      "\"New\",\n          \"click\": \"CreateNewDoc\"\n        }\n      ]\n   "
      " },\n    \"itemCount\": 3,\n    \"isShown\": true\n  }\n}\n";

  LoadResource(kJSON);
  EXPECT_EQ(GetDocument()
                .documentElement()
                ->QuerySelector(html_names::kBodyTag.LocalName())
                ->firstChild()
                ->textContent(),
            kJSON);

  // Format the resource.
  ClickPrettyPrintCheckbox();
  EXPECT_EQ(GetDocument()
                .documentElement()
                ->QuerySelector(html_names::kBodyTag.LocalName())
                ->firstChild()
                ->textContent(),
            kFormatted);

  // Uncheck the checkbox, which should restore the original formatting.
  ClickPrettyPrintCheckbox();
  EXPECT_EQ(GetDocument()
                .documentElement()
                ->QuerySelector(html_names::kBodyTag.LocalName())
                ->firstChild()
                ->textContent(),
            kJSON);
}

TEST_F(JSONDocumentTest, InvalidJSON) {
  LoadResource(
      "{\"menu:{\"id\":\"file\",\"value\":\"File\",\"popup\":{\"menuitem\":[{"
      "\"value\":\"New\",\"click\":\"CreateNewDoc\"}]},\"itemCount\":3,"
      "\"isShown\":true}}");
  EXPECT_EQ(
      GetDocument()
          .documentElement()
          ->QuerySelector(html_names::kBodyTag.LocalName())
          ->firstChild()
          ->textContent(),
      "{\"menu:{\"id\":\"file\",\"value\":\"File\",\"popup\":{\"menuitem\":[{"
      "\"value\":\"New\",\"click\":\"CreateNewDoc\"}]},\"itemCount\":3,"
      "\"isShown\":true}}");
  ClickPrettyPrintCheckbox();
  EXPECT_EQ(GetDocument()
                .documentElement()
                ->QuerySelector(html_names::kBodyTag.LocalName())
                ->firstChild()
                ->textContent(),
            "{\"menu:{\"id\":\"file\",\"value\":\"File\",\"popup\":{"
            "\"menuitem\":[{\"value\":\"New\",\"click\":\"CreateNewDoc\"}]},"
            "\"itemCount\":3,\"isShown\":true}}");
}

TEST_F(JSONDocumentTest, Utf8Parsing) {
  LoadResource(
      "{\"interests\": [\"音楽\", \"खेल\", \"чтение\"],"
      "\"languages\": [\"Français\", \"Español\", \"日本語\", "
      "\"العربية\",\"ગુજરાતી\", \"தமிழ்\", \"తెలుగు\", "
      "\"ಕನ್ನಡ\"],\"emoji\":[\"✨\",\"🍬\",\"🌍\"] }");
  EXPECT_EQ(GetDocument()
                .documentElement()
                ->QuerySelector(html_names::kBodyTag.LocalName())
                ->firstChild()
                ->textContent(),
            "{\"interests\": [\"音楽\", \"खेल\", \"чтение\"],"
            "\"languages\": [\"Français\", \"Español\", \"日本語\", "
            "\"العربية\",\"ગુજરાતી\", \"தமிழ்\", \"తెలుగు\", "
            "\"ಕನ್ನಡ\"],\"emoji\":[\"✨\",\"🍬\","
            "\"🌍\"] }");
  ClickPrettyPrintCheckbox();
  EXPECT_EQ(GetDocument()
                .documentElement()
                ->QuerySelector(html_names::kBodyTag.LocalName())
                ->firstChild()
                ->textContent(),
            "{\n  \"interests\": [\n    \"音楽\",\n    \"खेल\",\n    "
            "\"чтение\"\n  ],\n  \"languages\": [\n    \"Français\",\n    "
            "\"Español\",\n    \"日本語\",\n    \"العربية\",\n    "
            "\"ગુજરાતી\",\n    \"தமிழ்\",\n    \"తెలుగు\",\n    \"ಕನ್ನಡ\"\n  ],\n  "
            "\"emoji\": [\n    \"✨\",\n    \"🍬\",\n    \"🌍\"\n  ]\n}\n");
}
}  // namespace blink
