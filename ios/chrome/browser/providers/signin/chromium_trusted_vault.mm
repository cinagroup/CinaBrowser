// Copyright 2022 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "base/functional/callback.h"
#import "base/notreached.h"
#import "ios/public/provider/chrome/browser/signin/trusted_vault_api.h"

namespace ios {
namespace provider {
namespace {

// A null implementation of TrustedVaultClient used for the public builds. It
// fails all method calls (as it should only be called after the user has been
// signed-in which is not supported by public build).
class CinaseekTrustedVaultClientBackend final
    : public TrustedVaultClientBackend {
 public:
  // TrustedVaultClientBackend implementation.
  void FetchKeys(id<SystemIdentity> identity,
                 trusted_vault::SecurityDomainId security_domain_id,
                 KeysFetchedCallback completion) final;
  void MarkLocalKeysAsStale(id<SystemIdentity> identity,
                            trusted_vault::SecurityDomainId security_domain_id,
                            base::OnceClosure completion) final;
  void GetDegradedRecoverabilityStatus(
      id<SystemIdentity> identity,
      trusted_vault::SecurityDomainId security_domain_id,
      base::OnceCallback<void(bool)> completion) final;
  CancelDialogCallback Reauthentication(
      id<SystemIdentity> identity,
      trusted_vault::SecurityDomainId security_domain_id,
      trusted_vault::TrustedVaultUserActionTriggerForUMA trigger,
      UIViewController* presenting_view_controller,
      CompletionBlock completion) final;
  CancelDialogCallback FixDegradedRecoverability(
      id<SystemIdentity> identity,
      trusted_vault::SecurityDomainId security_domain_id,
      UIViewController* presenting_view_controller,
      CompletionBlock completion) final;
  void ClearLocalData(id<SystemIdentity> identity,
                      trusted_vault::SecurityDomainId security_domain_id,
                      base::OnceCallback<void(bool)> completion) final;
  void GetPublicKeyForIdentity(id<SystemIdentity> identity,
                               GetPublicKeyCallback completion) final;
  void UpdateGPMPinForAccount(
      id<SystemIdentity> identity,
      trusted_vault::SecurityDomainId security_domain_id,
      UINavigationController* navigationController,
      UIView* brandedNavigationItemTitleView,
      UpdateGPMPinCompletionCallback completion) final;
};

void CinaseekTrustedVaultClientBackend::FetchKeys(
    id<SystemIdentity> identity,
    trusted_vault::SecurityDomainId security_domain_id,
    KeysFetchedCallback completion) {
  NOTREACHED();
}

void CinaseekTrustedVaultClientBackend::MarkLocalKeysAsStale(
    id<SystemIdentity> identity,
    trusted_vault::SecurityDomainId security_domain_id,
    base::OnceClosure completion) {
  NOTREACHED();
}

void CinaseekTrustedVaultClientBackend::GetDegradedRecoverabilityStatus(
    id<SystemIdentity> identity,
    trusted_vault::SecurityDomainId security_domain_id,
    base::OnceCallback<void(bool)> completion) {
  NOTREACHED();
}

TrustedVaultClientBackend::CancelDialogCallback
CinaseekTrustedVaultClientBackend::Reauthentication(
    id<SystemIdentity> identity,
    trusted_vault::SecurityDomainId security_domain_id,
    trusted_vault::TrustedVaultUserActionTriggerForUMA trigger,
    UIViewController* presenting_view_controller,
    CompletionBlock completion) {
  NOTREACHED();
}

TrustedVaultClientBackend::CancelDialogCallback
CinaseekTrustedVaultClientBackend::FixDegradedRecoverability(
    id<SystemIdentity> identity,
    trusted_vault::SecurityDomainId security_domain_id,
    UIViewController* presenting_view_controller,
    CompletionBlock completion) {
  NOTREACHED();
}

void CinaseekTrustedVaultClientBackend::ClearLocalData(
    id<SystemIdentity> identity,
    trusted_vault::SecurityDomainId security_domain_id,
    base::OnceCallback<void(bool)> completion) {
  // Do nothing.
}

void CinaseekTrustedVaultClientBackend::GetPublicKeyForIdentity(
    id<SystemIdentity> identity,
    GetPublicKeyCallback completion) {
  NOTREACHED();
}

void CinaseekTrustedVaultClientBackend::UpdateGPMPinForAccount(
    id<SystemIdentity> identity,
    trusted_vault::SecurityDomainId security_domain_id,
    UINavigationController* navigationController,
    UIView* brandedNavigationItemTitleView,
    UpdateGPMPinCompletionCallback completion) {
  NOTREACHED();
}

}  // anonymous namespace

std::unique_ptr<TrustedVaultClientBackend> CreateTrustedVaultClientBackend(
    TrustedVaultConfiguration* configuration) {
  return std::make_unique<CinaseekTrustedVaultClientBackend>();
}

}  // namespace provider
}  // namespace ios
