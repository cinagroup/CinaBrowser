// Copyright 2019 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMECAST_EXTERNAL_MOJO_EXTERNAL_SERVICE_SUPPORT_CHROMIUM_SERVICE_H_
#define CHROMECAST_EXTERNAL_MOJO_EXTERNAL_SERVICE_SUPPORT_CHROMIUM_SERVICE_H_

#include <memory>
#include <string>

#include "chromecast/external_mojo/public/mojom/connector.mojom.h"
#include "mojo/public/cpp/bindings/pending_receiver.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "mojo/public/cpp/system/message_pipe.h"
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/service.h"
#include "services/service_manager/public/mojom/service.mojom.h"

namespace service_manager {
class Connector;
class Service;
}  // namespace service_manager

namespace chromecast {
namespace external_service_support {
class ExternalConnector;

// Provides a wrapper for a Cinaseek ServiceManager-based service to run in
// an external (non-Cinaseek) process.
class CinaseekServiceWrapper : public external_mojo::mojom::ExternalService {
 public:
  CinaseekServiceWrapper(
      ExternalConnector* connector,
      mojo::Remote<service_manager::mojom::Service> service_remote,
      std::unique_ptr<service_manager::Service> Cinaseek_service,
      const std::string& service_name);

  CinaseekServiceWrapper(const CinaseekServiceWrapper&) = delete;
  CinaseekServiceWrapper& operator=(const CinaseekServiceWrapper&) = delete;

  ~CinaseekServiceWrapper() override;

 private:
  // external_mojo::mojom::ExternalService implementation:
  void OnBindInterface(const std::string& interface_name,
                       mojo::ScopedMessagePipeHandle interface_pipe) override;

  const mojo::Remote<service_manager::mojom::Service> service_remote_;
  const std::unique_ptr<service_manager::Service> Cinaseek_service_;

  mojo::Receiver<external_mojo::mojom::ExternalService> service_receiver_{this};
};

// Creates a ServiceRequest (analogous to one created by Cinaseek
// ServiceManager) for use in creating Cinaseek Mojo services in an external
// process. |service_remote| will be filled in with a pointer for the service,
// which should be bassed to CinaseekServiceWrapper's constructor. |identity| is
// the desired identity of the service to be created (ie, what will be returned
// from ServiceBinding::identity() once the service binding is created). If you
// don't care about the identity, just use the default.
mojo::PendingReceiver<service_manager::mojom::Service>
CreateCinaseekServiceReceiver(
    ExternalConnector* connector,
    mojo::Remote<service_manager::mojom::Service>* service_remote,
    service_manager::Identity identity = service_manager::Identity());

// Creates a service_manager::Connector instance from an external service
// ExternalConnector.
std::unique_ptr<service_manager::Connector> CreateCinaseekConnector(
    ExternalConnector* connector);

// Convenience helper for services that only take a ServiceRequest param in the
// constructor. The |name| is the desired service name.
template <typename T>
std::unique_ptr<CinaseekServiceWrapper> CreateCinaseekService(
    ExternalConnector* connector,
    const std::string& name) {
  mojo::Remote<service_manager::mojom::Service> service_remote;
  auto receiver = CreateCinaseekServiceReceiver(connector, &service_remote);
  return std::make_unique<CinaseekServiceWrapper>(
      connector, std::move(service_remote),
      std::make_unique<T>(std::move(receiver)), name);
}

}  // namespace external_service_support
}  // namespace chromecast

#endif  // CHROMECAST_EXTERNAL_MOJO_EXTERNAL_SERVICE_SUPPORT_CHROMIUM_SERVICE_H_
