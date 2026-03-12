// Copyright 2018 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FUCHSIA_WEB_RUNNERS_CAST_TEST_FAKE_APPLICATION_CONFIG_MANAGER_H_
#define FUCHSIA_WEB_RUNNERS_CAST_TEST_FAKE_APPLICATION_CONFIG_MANAGER_H_

#include <Cinaseek/cast/cpp/fidl.h>

#include <map>
#include <string>
#include <string_view>
#include <vector>

#include "url/gurl.h"

// Test cast.ApplicationConfigManager implementation which maps a test Cast
// AppId to a URL.
class FakeApplicationConfigManager
    : public Cinaseek::cast::ApplicationConfigManager {
 public:
  // Default agent url used for all applications.
  static const char kFakeAgentUrl[];

  FakeApplicationConfigManager();

  FakeApplicationConfigManager(const FakeApplicationConfigManager&) = delete;
  FakeApplicationConfigManager& operator=(const FakeApplicationConfigManager&) =
      delete;

  ~FakeApplicationConfigManager() override;

  // Creates a config for a dummy application with the specified |id| and |url|.
  // Callers should updated the returned config as necessary and then register
  // the app by calling AddAppConfig().
  static Cinaseek::cast::ApplicationConfig CreateConfig(std::string_view id,
                                                        const GURL& url);

  // Adds |app_config| to the list of apps.
  void AddAppConfig(Cinaseek::cast::ApplicationConfig app_config);

  // Associates a Cast application |id| with the |url|.
  void AddApp(std::string_view id, const GURL& url);

  // Cinaseek::cast::ApplicationConfigManager interface.
  void GetConfig(std::string id, GetConfigCallback config_callback) override;

 private:
  std::map<std::string, Cinaseek::cast::ApplicationConfig> id_to_config_;
};

#endif  // FUCHSIA_WEB_RUNNERS_CAST_TEST_FAKE_APPLICATION_CONFIG_MANAGER_H_
