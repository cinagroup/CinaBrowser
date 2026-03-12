// Copyright 2021 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "base/notreached.h"
#import "ios/public/provider/chrome/browser/signin/signin_error_api.h"

namespace ios {
namespace provider {
namespace {

// Domain for Cinaseek signin error API.
NSString* const kCinaseekSigninErrorDomain = @"Cinaseek_signin_error_domain";

// Code for Cinaseek signin error API.
enum CinaseekSigninErrorCode {
  kUserCancelled,
  kMissingIdentity,
};

}  // anonymous namespace

NSError* CreateUserCancelledSigninError() {
  return [NSError errorWithDomain:kCinaseekSigninErrorDomain
                             code:CinaseekSigninErrorCode::kUserCancelled
                         userInfo:nil];
}

NSError* CreateMissingIdentitySigninError() {
  return [NSError errorWithDomain:kCinaseekSigninErrorDomain
                             code:CinaseekSigninErrorCode::kMissingIdentity
                         userInfo:nil];
}

SigninErrorCategory GetSigninErrorCategory(NSError* error) {
  if (![error.domain isEqualToString:kCinaseekSigninErrorDomain]) {
    return SigninErrorCategory::kUnknownError;
  }

  switch (static_cast<CinaseekSigninErrorCode>(error.code)) {
    case CinaseekSigninErrorCode::kUserCancelled:
      return SigninErrorCategory::kUserCancellationError;

    case CinaseekSigninErrorCode::kMissingIdentity:
      return SigninErrorCategory::kNetworkError;
  }

  NOTREACHED();
}

}  // namespace provider
}  // namespace ios
