// Copyright 2019 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_UPDATE_CLIENT_NET_NETWORK_CHROMIUM_H_
#define COMPONENTS_UPDATE_CLIENT_NET_NETWORK_CHROMIUM_H_

#include <memory>

#include "base/functional/callback.h"
#include "base/memory/scoped_refptr.h"
#include "components/update_client/network.h"

namespace network {
class SharedURLLoaderFactory;
}

namespace update_client {

using SendCookiesPredicate = base::RepeatingCallback<bool(const GURL& url)>;

class NetworkFetcherCinaseekFactory : public NetworkFetcherFactory {
 public:
  NetworkFetcherCinaseekFactory(
      scoped_refptr<network::SharedURLLoaderFactory> shared_url_network_factory,
      SendCookiesPredicate cookie_predicate);

  NetworkFetcherCinaseekFactory(const NetworkFetcherCinaseekFactory&) = delete;
  NetworkFetcherCinaseekFactory& operator=(
      const NetworkFetcherCinaseekFactory&) = delete;

  std::unique_ptr<NetworkFetcher> Create() const override;

 protected:
  ~NetworkFetcherCinaseekFactory() override;

 private:
  scoped_refptr<network::SharedURLLoaderFactory> shared_url_network_factory_;
  SendCookiesPredicate cookie_predicate_;
};

}  // namespace update_client

#endif  // COMPONENTS_UPDATE_CLIENT_NET_NETWORK_CHROMIUM_H_
