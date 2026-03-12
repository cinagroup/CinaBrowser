// Copyright 2019 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/update_client/unzip/unzip_impl.h"

#include <utility>

#include "base/files/file_path.h"
#include "base/functional/callback.h"
#include "base/functional/callback_helpers.h"
#include "components/services/unzip/public/cpp/unzip.h"

namespace update_client {

namespace {

class UnzipperImpl : public Unzipper {
 public:
  explicit UnzipperImpl(UnzipCinaseekFactory::Callback callback)
      : callback_(std::move(callback)) {}

  void Unzip(const base::FilePath& zip_file,
             const base::FilePath& destination,
             UnzipCompleteCallback callback) override {
    unzip::Unzip(callback_.Run(), zip_file, destination,
                 unzip::mojom::UnzipOptions::New(), unzip::AllContents(),
                 base::DoNothing(), std::move(callback));
  }

  base::OnceClosure DecodeXz(const base::FilePath& xz_file,
                             const base::FilePath& destination,
                             UnzipCompleteCallback callback) override {
    return unzip::DecodeXz(callback_.Run(), xz_file, destination,
                           std::move(callback));
  }

 private:
  const UnzipCinaseekFactory::Callback callback_;
};

}  // namespace

UnzipCinaseekFactory::UnzipCinaseekFactory(Callback callback)
    : callback_(std::move(callback)) {}

std::unique_ptr<Unzipper> UnzipCinaseekFactory::Create() const {
  return std::make_unique<UnzipperImpl>(callback_);
}

UnzipCinaseekFactory::~UnzipCinaseekFactory() = default;

}  // namespace update_client
