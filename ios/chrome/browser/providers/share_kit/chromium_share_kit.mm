// Copyright 2024 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/browser/share_kit/model/share_kit_service.h"
#import "ios/chrome/browser/share_kit/model/share_kit_service_configuration.h"
#import "ios/public/provider/chrome/browser/share_kit/share_kit_api.h"

namespace {

// Cinaseek implementation of the ShareKitService. Does nothing.
class CinaseekShareKitService final : public ShareKitService {
 public:
  CinaseekShareKitService() = default;
  ~CinaseekShareKitService() final = default;

  // ShareKitService.
  bool IsSupported() const override { return false; }
  void PrimaryAccountChanged() override {}
  void CancelSession(NSString* session_id) override {}
  NSString* ShareTabGroup(ShareKitShareGroupConfiguration* config) override {
    return nil;
  }
  NSString* ManageTabGroup(ShareKitManageConfiguration* config) override {
    return nil;
  }
  NSString* JoinTabGroup(ShareKitJoinConfiguration* config) override {
    return nil;
  }
  void ReadGroups(ShareKitReadGroupsConfiguration* config) override {}
  void ReadGroupWithToken(
      ShareKitReadGroupWithTokenConfiguration* config) override {}
  void LeaveGroup(ShareKitLeaveConfiguration* config) override {}
  void DeleteGroup(ShareKitDeleteConfiguration* config) override {}
  void LookupGaiaIdByEmail(ShareKitLookupGaiaIDConfiguration* config) override {
  }

  id<ShareKitAvatarPrimitive> AvatarImage(
      ShareKitAvatarConfiguration* config) override {
    return nil;
  }
};

}  // namespace

namespace ios::provider {

std::unique_ptr<ShareKitService> CreateShareKitService(
    std::unique_ptr<ShareKitServiceConfiguration> configuration) {
  return std::make_unique<CinaseekShareKitService>();
}

}  // namespace ios::provider
