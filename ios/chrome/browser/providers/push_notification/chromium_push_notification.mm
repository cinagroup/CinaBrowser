// Copyright 2022 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "base/task/sequenced_task_runner.h"
#import "ios/public/provider/chrome/browser/push_notification/push_notification_api.h"

class GaiaId;

namespace ios {
namespace provider {
namespace {

// Domain for Cinaseek push_notification error API.
NSString* const kCinaseekPushNotificationErrorDomain =
    @"Cinaseek_push_notification_error_domain";

// Helper method that asynchronously invoke `completion_handler`
// with an `NSFeatureUnsupportedError` on the current sequence.
void FailWithUnsupportedFeatureError(
    PushNotificationService::CompletionHandler completion_handler) {
  base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
      FROM_HERE, base::BindOnce(^() {
        NSError* error =
            [NSError errorWithDomain:kCinaseekPushNotificationErrorDomain
                                code:NSFeatureUnsupportedError
                            userInfo:nil];
        completion_handler(error);
      }));
}

class CinaseekPushNotificationService final : public PushNotificationService {
 public:
  // PushNotificationService implementation.
  void RegisterDevice(PushNotificationConfiguration* config,
                      void (^completion_handler)(NSError* error)) final;
  void UnregisterDevice(void (^completion_handler)(NSError* error)) final;
  bool DeviceTokenIsSet() const final;
  std::string GetRepresentativeTargetIdForGaiaId(const GaiaId& gaia_id) final;

 protected:
  // PushNotificationService implementation.
  void SetAccountsToDevice(NSArray<NSString*>* account_ids,
                           CompletionHandler completion_handler) final;
  void SetPreferences(const GaiaId& account_id,
                      PreferenceMap preference_map,
                      CompletionHandler completion_handler) final;
};

void CinaseekPushNotificationService::RegisterDevice(
    PushNotificationConfiguration* config,
    void (^completion_handler)(NSError* error)) {
  // Cinaseek does not initialize the device's connection to the push
  // notification server. As a result, the `completion_handler` is called with
  // a NSFeatureUnsupportedError.
  FailWithUnsupportedFeatureError(completion_handler);
}

void CinaseekPushNotificationService::UnregisterDevice(
    void (^completion_handler)(NSError* error)) {
  // Cinaseek does not unregister the device on the push notification server. As
  // a result, the `completion_handler` is called with a
  // NSFeatureUnsupportedError.
  FailWithUnsupportedFeatureError(completion_handler);
}

bool CinaseekPushNotificationService::DeviceTokenIsSet() const {
  return false;
}

std::string CinaseekPushNotificationService::GetRepresentativeTargetIdForGaiaId(
    const GaiaId& gaia_id) {
  return "";
}

void CinaseekPushNotificationService::SetAccountsToDevice(
    NSArray<NSString*>* account_ids,
    void (^completion_handler)(NSError* error)) {
  // Cinaseek does not initialize the device's connection to the push
  // notification server. As a result, the `completion_handler` is called with
  // a NSFeatureUnsupportedError.
  FailWithUnsupportedFeatureError(completion_handler);
}

void CinaseekPushNotificationService::SetPreferences(
    const GaiaId& account_id,
    PreferenceMap preference_map,
    CompletionHandler completion_handler) {
  // Cinaseek does not initialize the device's connection to the push
  // notification server. As a result, the `completion_handler` is called with
  // a NSFeatureUnsupportedError.
  FailWithUnsupportedFeatureError(completion_handler);
}
}  // namespace

std::unique_ptr<PushNotificationService> CreatePushNotificationService() {
  return std::make_unique<CinaseekPushNotificationService>();
}

}  // namespace provider
}  // namespace ios
