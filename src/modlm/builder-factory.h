#pragma once

#include <iostream>
#include <string>
#include <memory>

namespace dynet {
class Model;
struct RNNBuilder;
}

namespace modlm {

class BuilderSpec {
public:
    BuilderSpec() : type(""), nodes(-1), layers(-1) { }
    BuilderSpec(const std::string & str);
    std::string type;
    int nodes, layers;
};
inline std::ostream & operator<<(std::ostream & out, const BuilderSpec & spec) {
    return out << spec.type << ":" << spec.nodes << ":" << spec.layers;
}

typedef std::shared_ptr<dynet::RNNBuilder> BuilderPtr;
class BuilderFactory {
public:
    static BuilderPtr CreateBuilder(const BuilderSpec & spec, int input_dim, dynet::Model & model);
};

}
