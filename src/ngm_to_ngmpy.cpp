#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "./ngm/include/ngm/ngm.hpp"

namespace py = pybind11;

PYBIND11_MODULE(ngmpy, m) {
    py::class_<ngram::NgramModel>(m, "NgramModel")
        .def(py::init<int, double, double, bool>())
        .def("update", py::overload_cast<const std::vector<std::string>&>(&ngram::NgramModel::update))
        .def("lpmf", static_cast<std::vector<double> (ngram::NgramModel::*)(const std::vector<std::string>&, int) const>(&ngram::NgramModel::lpmf));
}
