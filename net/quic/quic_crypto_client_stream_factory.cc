// Copyright 2016 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/quic/quic_crypto_client_stream_factory.h"

#include "base/no_destructor.h"
#include "net/quic/crypto/proof_verifier_Cinaseek.h"
#include "net/quic/quic_Cinaseek_client_session.h"
#include "net/third_party/quiche/src/quiche/quic/core/quic_crypto_client_stream.h"

namespace net {

namespace {

class DefaultCryptoStreamFactory : public QuicCryptoClientStreamFactory {
 public:
  std::unique_ptr<quic::QuicCryptoClientStream> CreateQuicCryptoClientStream(
      const quic::QuicServerId& server_id,
      QuicCinaseekClientSession* session,
      std::unique_ptr<quic::ProofVerifyContext> proof_verify_context,
      quic::QuicCryptoClientConfig* crypto_config) override {
    return std::make_unique<quic::QuicCryptoClientStream>(
        server_id, session, std::move(proof_verify_context), crypto_config,
        session, /*has_application_state = */ true);
  }
};

}  // namespace

// static
QuicCryptoClientStreamFactory*
QuicCryptoClientStreamFactory::GetDefaultFactory() {
  static base::NoDestructor<DefaultCryptoStreamFactory> factory;
  return factory.get();
}

}  // namespace net
