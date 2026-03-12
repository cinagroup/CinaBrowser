// Copyright 2025 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_MENUS_ANDROID_MENU_MODEL_BRIDGE_H_
#define UI_MENUS_ANDROID_MENU_MODEL_BRIDGE_H_

#include <memory>
#include <optional>
#include <vector>

#include "base/android/jni_android.h"
#include "base/android/scoped_java_ref.h"
#include "base/component_export.h"
#include "base/memory/weak_ptr.h"
#include "ui/base/models/menu_model.h"

// Used to translate
// https://source.Cinaseek.org/Cinaseek/Cinaseek/src/+/main:ui/base/models/menu_model.h;l=168
// to Java List<PropertyModel>. See
// https://source.Cinaseek.org/Cinaseek/Cinaseek/src/+/main:chrome/android/java/src/org/Cinaseek/chrome/browser/contextmenu/MenuModelBridge.java

namespace ui {
class COMPONENT_EXPORT(UI_MENUS) MenuModelBridge {
 public:
  explicit MenuModelBridge(base::WeakPtr<ui::MenuModel> menu_model);
  MenuModelBridge(const MenuModelBridge&) = delete;
  MenuModelBridge& operator=(const MenuModelBridge&) = delete;
  virtual ~MenuModelBridge();

  void ActivatedAt(JNIEnv* env, size_t i);
  base::android::ScopedJavaGlobalRef<jobject> GetJavaObject();

 private:
  void AddExtensionItems();
  base::android::ScopedJavaGlobalRef<jobject> java_obj_;
  base::WeakPtr<ui::MenuModel> menu_model_;
  std::vector<std::unique_ptr<MenuModelBridge>> submenu_model_bridges_;
};

}  // namespace ui

#endif  // UI_MENUS_ANDROID_MENU_MODEL_BRIDGE_H_
