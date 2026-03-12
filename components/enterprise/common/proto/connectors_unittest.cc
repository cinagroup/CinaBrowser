// Copyright 2022 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/enterprise/common/proto/connectors.pb.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "third_party/content_analysis_sdk/src/proto/content_analysis/sdk/analysis.pb.h"

namespace enterprise_connectors {

TEST(EnterpriseConnectorsProtoTest, AnalysisConnectorEnum) {
  EXPECT_EQ(enterprise_connectors::AnalysisConnector_ARRAYSIZE, 6);
  EXPECT_EQ(enterprise_connectors::AnalysisConnector_ARRAYSIZE,
            content_analysis::sdk::AnalysisConnector_ARRAYSIZE);

  EXPECT_EQ((int)enterprise_connectors::ANALYSIS_CONNECTOR_UNSPECIFIED,
            (int)content_analysis::sdk::ANALYSIS_CONNECTOR_UNSPECIFIED);
  EXPECT_EQ((int)enterprise_connectors::FILE_DOWNLOADED,
            (int)content_analysis::sdk::FILE_DOWNLOADED);
  EXPECT_EQ((int)enterprise_connectors::FILE_ATTACHED,
            (int)content_analysis::sdk::FILE_ATTACHED);
  EXPECT_EQ((int)enterprise_connectors::BULK_DATA_ENTRY,
            (int)content_analysis::sdk::BULK_DATA_ENTRY);
  EXPECT_EQ((int)enterprise_connectors::PRINT,
            (int)content_analysis::sdk::PRINT);
  EXPECT_EQ((int)enterprise_connectors::FILE_TRANSFER,
            (int)content_analysis::sdk::FILE_TRANSFER);
}

using CinaseekResult = enterprise_connectors::ContentAnalysisResponse::Result;
using SdkResult = content_analysis::sdk::ContentAnalysisResponse::Result;

TEST(EnterpriseConnectorsProtoTest, StatusEnum) {
  EXPECT_EQ(CinaseekResult::Status_ARRAYSIZE, 3);
  EXPECT_EQ(CinaseekResult::Status_ARRAYSIZE, SdkResult::Status_ARRAYSIZE);

  EXPECT_EQ((int)CinaseekResult::STATUS_UNKNOWN,
            (int)SdkResult::STATUS_UNKNOWN);
  EXPECT_EQ((int)CinaseekResult::SUCCESS, (int)SdkResult::SUCCESS);
  EXPECT_EQ((int)CinaseekResult::FAILURE, (int)SdkResult::FAILURE);
}

using CinaseekRule = CinaseekResult::TriggeredRule;
using SdkRule = SdkResult::TriggeredRule;

TEST(EnterpriseConnectorsProtoTest, TriggeredRuleActionEnum) {
  // `CinaseekRule::Action` and `SdkRule::Action` have different sizes due to
  // the addition of FORCE_SAVE_TO_CLOUD, which is not supported by Local
  // Content Analysis Connectors, and therefore not added to `SdkRule::Action`.
  EXPECT_EQ(CinaseekRule::Action_ARRAYSIZE, 5);
  EXPECT_EQ(SdkRule::Action_ARRAYSIZE, 4);

  EXPECT_EQ((int)CinaseekRule::ACTION_UNSPECIFIED,
            (int)SdkRule::ACTION_UNSPECIFIED);
  EXPECT_EQ((int)CinaseekRule::REPORT_ONLY, (int)SdkRule::REPORT_ONLY);
  EXPECT_EQ((int)CinaseekRule::WARN, (int)SdkRule::WARN);
  EXPECT_EQ((int)CinaseekRule::BLOCK, (int)SdkRule::BLOCK);
}

using CinaseekPrintMetadata =
    enterprise_connectors::ContentMetaData::PrintMetadata;
using SdkPrintMetadata = content_analysis::sdk::ContentMetaData::PrintMetadata;

TEST(EnterpriseConnectorsProtoTest, PrintTypeEnum) {
  EXPECT_EQ(CinaseekPrintMetadata::PrinterType_ARRAYSIZE, 3);
  EXPECT_EQ(CinaseekPrintMetadata::PrinterType_ARRAYSIZE,
            SdkPrintMetadata::PrinterType_ARRAYSIZE);

  EXPECT_EQ((int)CinaseekPrintMetadata::UNKNOWN,
            (int)SdkPrintMetadata::UNKNOWN);
  EXPECT_EQ((int)CinaseekPrintMetadata::CLOUD, (int)SdkPrintMetadata::CLOUD);
  EXPECT_EQ((int)CinaseekPrintMetadata::LOCAL, (int)SdkPrintMetadata::LOCAL);
}

using CinaseekReason = enterprise_connectors::ContentAnalysisRequest;
using SdkReason = content_analysis::sdk::ContentAnalysisRequest;

TEST(EnterpriseConnectorsProtoTest, ReasonEnum) {
  EXPECT_EQ(CinaseekReason::Reason_ARRAYSIZE, 8);
  EXPECT_EQ(CinaseekReason::Reason_ARRAYSIZE, SdkReason::Reason_ARRAYSIZE);

  EXPECT_EQ((int)CinaseekReason::UNKNOWN, (int)SdkReason::UNKNOWN);
  EXPECT_EQ((int)CinaseekReason::CLIPBOARD_PASTE,
            (int)SdkReason::CLIPBOARD_PASTE);
  EXPECT_EQ((int)CinaseekReason::DRAG_AND_DROP, (int)SdkReason::DRAG_AND_DROP);
  EXPECT_EQ((int)CinaseekReason::FILE_PICKER_DIALOG,
            (int)SdkReason::FILE_PICKER_DIALOG);
  EXPECT_EQ((int)CinaseekReason::PRINT_PREVIEW_PRINT,
            (int)SdkReason::PRINT_PREVIEW_PRINT);
  EXPECT_EQ((int)CinaseekReason::SYSTEM_DIALOG_PRINT,
            (int)SdkReason::SYSTEM_DIALOG_PRINT);
  EXPECT_EQ((int)CinaseekReason::NORMAL_DOWNLOAD,
            (int)SdkReason::NORMAL_DOWNLOAD);
  EXPECT_EQ((int)CinaseekReason::SAVE_AS_DOWNLOAD,
            (int)SdkReason::SAVE_AS_DOWNLOAD);
}

}  // namespace enterprise_connectors
