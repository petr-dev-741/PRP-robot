#include <memory>
#include <oneapi/tbb/partitioner.h>
#include <rclcpp/rclcpp.hpp>
#include "nodes/ionode.hpp"
#include "RosExampleClass.h"

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    auto executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();

    auto ionodeButton = std::make_shared<rclcpp::Node>("ionodeB");
    auto ionodeLED = std::make_shared<rclcpp::Node>("ionodeL");

    auto ioobjectButton = std::make_shared<nodes::IoNode>();
    auto ioobjectLED = std::make_shared<nodes::IoNode>();

    executor->add_node(ionodeButton);
    executor->add_node(ionodeLED);

    executor->spin();

    rclcpp::shutdown();
    return 0;
}