#pragma once

#include "mmedia/base/Packet.h"
#include <vector>
#include <memory>
#include <cstdint>

namespace tmms
{
    namespace live
    {
        using namespace tmms::mm;

        struct GopItemInfo
        {
            int32_t index;
            int64_t timestamp;
            GopItemInfo(int32_t i,int64_t t)
            :index(i),timestamp(t)
            {}
        };

        class GopMgr
        {
        public:
            GopMgr() = default;
            ~GopMgr(){};

            void AddFrame(const PacketPtr &packet);
            int32_t MaxGopLength() const;
            size_t GopSize() const;
            int GetGopByLatency(int content_latency, int &latency) const;
            void ClearExpriedGop(int min_idx);
            void PrintAllGop();
            int64_t LastestTimeStamp() const
            {
                return lastest_timestamp_;
            }
        private:
            std::vector<GopItemInfo> gops_;
            int32_t gop_length_{0};
            int32_t max_gop_length_{0};
            int32_t gop_numbers_{0};
            int32_t total_gop_length_{0};
            int64_t lastest_timestamp_{0};
        };

    }
}