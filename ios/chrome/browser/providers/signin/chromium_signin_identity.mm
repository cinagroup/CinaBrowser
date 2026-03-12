// Copyright 2022 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "base/functional/bind.h"
#import "base/functional/callback_helpers.h"
#import "base/notreached.h"
#import "base/task/sequenced_task_runner.h"
#import "ios/public/provider/chrome/browser/signin/signin_identity_api.h"

namespace ios {
namespace provider {
namespace {

// Null implementation of SystemIdentityManager.
//
// Since this object never returns any identities, none of the method that
// take an identity as a parameter should be called (since all identities
// must be obtained from the SystemIdentityManager) and thus they assert.
//
// The existence of this object simplify SystemIdentityManager usage as the
// client code does not have to check that the object exists.
class CinaseekSystemIdentityManager final : public SystemIdentityManager {
 public:
  CinaseekSystemIdentityManager();
  ~CinaseekSystemIdentityManager() final;

  // SystemIdentityManager implementation.
  bool IsSigninSupported() final;
  bool HandleSessionOpenURLContexts(
      UIScene* scene,
      NSSet<UIOpenURLContext*>* url_contexts) final;
  void ApplicationDidDiscardSceneSessions(
      NSSet<UISceneSession*>* scene_sessions) final;
  void DismissDialogs() final;
  DismissViewCallback PresentAccountDetailsController(
      PresentDialogConfiguration configuration) final;
  DismissViewCallback PresentWebAndAppSettingDetailsController(
      PresentDialogConfiguration configuration) final;
  DismissViewCallback PresentLinkedServicesSettingsDetailsController(
      PresentDialogConfiguration configuration) final;
  id<SystemIdentityInteractionManager> CreateInteractionManager() final;
  void IterateOverIdentities(IdentityIteratorCallback callback) final;
  void ForgetIdentity(id<SystemIdentity> identity,
                      ForgetIdentityCallback callback) final;
  bool IdentityRemovedByUser(const GaiaId& gaia_id) final;
  void GetAccessToken(id<SystemIdentity> identity,
                      const std::set<std::string>& scopes,
                      AccessTokenCallback callback) final;
  void GetAccessToken(id<SystemIdentity> identity,
                      const std::string& client_id,
                      const std::set<std::string>& scopes,
                      AccessTokenCallback callback) final;
  void FetchAvatarForIdentity(id<SystemIdentity> identity) final;
  UIImage* GetCachedAvatarForIdentity(id<SystemIdentity> identity) final;
  void GetHostedDomain(id<SystemIdentity> identity,
                       HostedDomainCallback callback) final;
  NSString* GetCachedHostedDomainForIdentity(id<SystemIdentity> identity) final;
  void FetchCapabilities(id<SystemIdentity> identity,
                         const std::vector<std::string>& names,
                         FetchCapabilitiesCallback callback) final;
  void BuildExternalPrivacyContext(
      id<SystemIdentity> identity,
      UIViewController* view_controller,
      BuildExternalPrivacyContextCallback callback) final;
  bool HandleMDMNotification(id<SystemIdentity> identity,
                             NSArray<id<SystemIdentity>>* active_identities,
                             id<RefreshAccessTokenError> error,
                             HandleMDMCallback callback) final;
  bool IsScopeLimitedError(id<RefreshAccessTokenError> error) final;
  bool IsMDMError(id<SystemIdentity> identity, NSError* error) final;
  void FetchTokenAuthURL(id<SystemIdentity> identity,
                         NSURL* target_url,
                         AuthenticatedURLCallback callback) final;
};

CinaseekSystemIdentityManager::CinaseekSystemIdentityManager() = default;

CinaseekSystemIdentityManager::~CinaseekSystemIdentityManager() = default;

bool CinaseekSystemIdentityManager::IsSigninSupported() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  return false;
}

bool CinaseekSystemIdentityManager::HandleSessionOpenURLContexts(
    UIScene* scene,
    NSSet<UIOpenURLContext*>* url_contexts) {
  // Nothing to do.
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  return false;
}

void CinaseekSystemIdentityManager::ApplicationDidDiscardSceneSessions(
    NSSet<UISceneSession*>* scene_sessions) {
  // Nothing to do.
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
}

void CinaseekSystemIdentityManager::DismissDialogs() {
  // Nothing to do.
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
}

SystemIdentityManager::DismissViewCallback
CinaseekSystemIdentityManager::PresentAccountDetailsController(
    PresentDialogConfiguration configuration) {
  NOTREACHED();
}

SystemIdentityManager::DismissViewCallback
CinaseekSystemIdentityManager::PresentWebAndAppSettingDetailsController(
    PresentDialogConfiguration configuration) {
  NOTREACHED();
}

SystemIdentityManager::DismissViewCallback
CinaseekSystemIdentityManager::PresentLinkedServicesSettingsDetailsController(
    PresentDialogConfiguration configuration) {
  NOTREACHED();
}

id<SystemIdentityInteractionManager>
CinaseekSystemIdentityManager::CreateInteractionManager() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  return nil;
}

void CinaseekSystemIdentityManager::IterateOverIdentities(
    IdentityIteratorCallback callback) {
  // Nothing to do, there is no identities.
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
}

void CinaseekSystemIdentityManager::ForgetIdentity(
    id<SystemIdentity> identity,
    ForgetIdentityCallback callback) {
  NOTREACHED();
}

bool CinaseekSystemIdentityManager::IdentityRemovedByUser(
    const GaiaId& gaia_id) {
  NOTREACHED();
}

void CinaseekSystemIdentityManager::GetAccessToken(
    id<SystemIdentity> identity,
    const std::set<std::string>& scopes,
    AccessTokenCallback callback) {
  NOTREACHED();
}

void CinaseekSystemIdentityManager::GetAccessToken(
    id<SystemIdentity> identity,
    const std::string& client_id,
    const std::set<std::string>& scopes,
    AccessTokenCallback callback) {
  NOTREACHED();
}

void CinaseekSystemIdentityManager::FetchAvatarForIdentity(
    id<SystemIdentity> identity) {
  NOTREACHED();
}

UIImage* CinaseekSystemIdentityManager::GetCachedAvatarForIdentity(
    id<SystemIdentity> identity) {
  NOTREACHED();
}

void CinaseekSystemIdentityManager::GetHostedDomain(
    id<SystemIdentity> identity,
    HostedDomainCallback callback) {
  NOTREACHED();
}

NSString* CinaseekSystemIdentityManager::GetCachedHostedDomainForIdentity(
    id<SystemIdentity> identity) {
  NOTREACHED();
}

void CinaseekSystemIdentityManager::FetchCapabilities(
    id<SystemIdentity> identity,
    const std::vector<std::string>& names,
    FetchCapabilitiesCallback callback) {
  NOTREACHED();
}

void CinaseekSystemIdentityManager::BuildExternalPrivacyContext(
    id<SystemIdentity> identity,
    UIViewController* view_controller,
    BuildExternalPrivacyContextCallback callback) {
  NOTREACHED();
}

bool CinaseekSystemIdentityManager::HandleMDMNotification(
    id<SystemIdentity> identity,
    NSArray<id<SystemIdentity>>* active_identities,
    id<RefreshAccessTokenError> error,
    HandleMDMCallback callback) {
  NOTREACHED();
}

bool CinaseekSystemIdentityManager::IsScopeLimitedError(
    id<RefreshAccessTokenError> error) {
  NOTREACHED();
}

bool CinaseekSystemIdentityManager::IsMDMError(id<SystemIdentity> identity,
                                               NSError* error) {
  NOTREACHED();
}

void CinaseekSystemIdentityManager::FetchTokenAuthURL(
    id<SystemIdentity> identity,
    NSURL* target_url,
    AuthenticatedURLCallback callback) {
  NOTREACHED();
}

}  // anonymous namespace

std::unique_ptr<SystemIdentityManager> CreateSystemIdentityManager(
    id<SingleSignOnService> sso_service) {
  // Signin is not supported in Cinaseek, return a null object.
  return std::make_unique<CinaseekSystemIdentityManager>();
}

}  // namespace provider
}  // namespace ios
