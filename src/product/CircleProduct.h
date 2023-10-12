#pragma once
#include "BaseProduct.h"
#include "CircleProductDataWapper.h"
#include "CircleProductTimeWapper.h"
#include "Logger.h"
#include "Utils.h"
#include <memory>
#include <mutex>
#include <vector>
class CircleProduct : public BaseProduct
{
  public:
    explicit CircleProduct();
    virtual ~CircleProduct() = default;
    virtual void signalQR(uint32_t pdNum = 0) override;
    virtual void signalComplete() override;

    virtual uint32_t updateQRCode(const std::string &code) override;
    virtual uint32_t updateLocation(const cv::Mat &mat, const std::string &path) override;
    virtual uint32_t updateCheck(const cv::Mat &mat, const std::string &path) override;
    virtual uint32_t updateOCR(const cv::Mat &mat, const std::string &path) override;

  private:
    uint16_t OffsetQRCode = 0;
    uint16_t OffsetLocate = 3;
    uint16_t OffsetLocateCheck = 6;
    uint16_t OffsetCoding = 9;
    uint16_t OffsetOCR = 14;
    // uint32_t
};

class CircleProductData : public ProductData
{
  public:
    CircleProductData() = default;
    ~CircleProductData() = default;
    virtual void zeroClear()
    {
        countAll = 0;
        countPass = 0;
        countWaste = 0;
        countLocateWaste = 0;
        countCodeWaste = 0;
        countPauseWaste = 0;
    };
    uint32_t countLocateWaste = 0; // 定位废品数
    uint32_t countCodeWaste = 0;   // 喷码废品数
    uint32_t countPauseWaste = 0;  // 暂停/终止废品数
};
