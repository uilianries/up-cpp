/*
 * Copyright (c) 2023 General Motors GTO LLC
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 * SPDX-FileType: SOURCE
 * SPDX-FileCopyrightText: 2023 General Motors GTO LLC
 * SPDX-License-Identifier: Apache-2.0
 */
#include <gtest/gtest.h>
#include <up-cpp/transport/datamodel/UPayload.h>

using namespace uprotocol::utransport;

// Test fixture for UPayload class
class UPayloadTest : public ::testing::Test
{
protected:
    // Test objects
    const uint8_t* testData = reinterpret_cast<const uint8_t*>("Hello, World!");
    const size_t testDataSize = 13;
    uprotocol::utransport::UPayload payload;

    UPayloadTest() : payload(testData, testDataSize, UPayloadType::VALUE) {}
};

// Test the data() method
TEST_F(UPayloadTest, Data)
{
    EXPECT_EQ(payload.data(), testData);
}

// Test the size() method
TEST_F(UPayloadTest, Size)
{
    EXPECT_EQ(payload.size(), testDataSize);
}

// Test the isEmpty() method with non-empty payload
TEST_F(UPayloadTest, IsEmptyFalse)
{
    EXPECT_FALSE(payload.isEmpty());
}

// Test the isEmpty() method with an empty payload
TEST(UPayloadTest, IsEmptyTrue) 
{
    uprotocol::utransport::UPayload emptyPayload(nullptr, 0, UPayloadType::VALUE);
    EXPECT_TRUE(emptyPayload.isEmpty());
}

int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}