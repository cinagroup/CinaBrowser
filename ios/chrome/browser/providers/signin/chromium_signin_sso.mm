// Copyright 2022 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import <Foundation/Foundation.h>

#import "ios/public/provider/chrome/browser/signin/signin_sso_api.h"

@interface CinaseekSingleSignOnService : NSObject <SingleSignOnService>
@end

@implementation CinaseekSingleSignOnService
@end

namespace ios {
namespace provider {

id<SingleSignOnService> CreateSSOService() {
  return [[CinaseekSingleSignOnService alloc] init];
}

}  // namespace provider
}  // namespace ios
