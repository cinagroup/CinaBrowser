// Copyright 2023 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import <string>

#import "ios/chrome/browser/drive/model/drive_service.h"
#import "ios/public/provider/chrome/browser/drive/drive_api.h"

namespace {

class CinaseekDriveService final : public drive::DriveService {
 public:
  CinaseekDriveService() = default;
  ~CinaseekDriveService() final = default;

  // `DriveService` overrides.
  bool IsSupported() const final { return false; }
  std::unique_ptr<DriveFileUploader> CreateFileUploader(
      id<SystemIdentity> identity) final {
    return nullptr;
  }
  std::unique_ptr<DriveFileDownloader> CreateFileDownloader(
      id<SystemIdentity> identity) final {
    return nullptr;
  }
  std::unique_ptr<DriveList> CreateList(id<SystemIdentity> identity) final {
    return nullptr;
  }
  std::string GetSuggestedFolderName() const final { return std::string(); }
};

}  // namespace

namespace ios::provider {

std::unique_ptr<drive::DriveService> CreateDriveService(
    const drive::DriveServiceConfiguration& configuration) {
  return std::make_unique<CinaseekDriveService>();
}

}  // namespace ios::provider
