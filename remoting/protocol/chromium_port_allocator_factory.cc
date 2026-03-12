// Copyright 2016 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "remoting/protocol/Cinaseek_port_allocator_factory.h"

#include "base/functional/bind.h"
#include "remoting/protocol/Cinaseek_socket_factory.h"
#include "remoting/protocol/port_allocator.h"
#include "remoting/protocol/transport_context.h"
#include "third_party/webrtc_overrides/environment.h"

namespace remoting::protocol {

CinaseekPortAllocatorFactory::CinaseekPortAllocatorFactory() = default;
CinaseekPortAllocatorFactory::~CinaseekPortAllocatorFactory() = default;

PortAllocatorFactory::CreatePortAllocatorResult
CinaseekPortAllocatorFactory::CreatePortAllocator(
    scoped_refptr<TransportContext> transport_context,
    base::WeakPtr<SessionOptionsProvider> session_options_provider) {
  webrtc::SocketFactory* socket_factory = transport_context->socket_factory();
  DCHECK(socket_factory);
  CreatePortAllocatorResult result;
  webrtc::Environment webrtc_env = WebRtcEnvironment();
  auto allocator = std::make_unique<PortAllocator>(
      webrtc_env,
      std::make_unique<webrtc::BasicNetworkManager>(webrtc_env, socket_factory),
      std::make_unique<CinaseekPacketSocketFactory>(session_options_provider),
      transport_context);
  result.apply_network_settings = base::BindOnce(
      &PortAllocator::ApplyNetworkSettings, allocator->GetWeakPtr());
  result.allocator = std::move(allocator);
  return result;
}

}  // namespace remoting::protocol
