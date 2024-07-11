#include "CircleProduct.h"
#include "BaseProduct.h"
#include <string>

CircleProduct::CircleProduct()
{
    pdType_ = TypeProduct::TypeCircle;
}

void CircleProduct::init(const YAML::Node &config)
{
    std::string strSubType = config["product"]["sub_type"].as<std::string>();
    if (strSubType == "antiClockWise")
    {
        subType_ = SubType::AntiClockWise;
    }
    else
    {
        subType_ = SubType::ClockWise;
    }
    roundOffset_ = config["product"]["round_offset"].as<int>();
    squareOffset_ = config["product"]["square_offset"].as<int>();
    BaseProduct::init(config);
}
