// Anthony Vasquez
// CPSC 120-04
// 2022-11-20
// kwortman@fullerton.edu
// @dskoman
//
// Lab 11-01
// Partners: @christianr6 @rtrinh02
//
// Finds state-related statistics
//

#include "states.h"

#include <fstream>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename,
                                              int columns) {
  std::vector<std::vector<std::string>> table;
  std::ifstream file(csv_filename);

  // read each row
  while (file.good()) {
    std::vector<std::string> row;
    // read each column
    for (int i = 0; i < columns; ++i) {
      std::string cell;
      file.ignore(1, '"');  // leading quote
      std::getline(file, cell, '"');
      if (i < (columns - 1)) {
        file.ignore(1, ',');  // comma
      }
      row.push_back(cell);
    }
    if (file.good()) {
      table.push_back(row);
    }
  }

  return table;
}

State::State(const std::string& name, int population, double land_area)
    : name_(name), population_(population), land_area_(land_area) {}

State::State() : name_(""), population_(0), land_area_(0.0) {}

const std::string& State::Name() const { return name_; }

int State::Population() const { return population_; }

double State::LandArea() const { return land_area_; }

double State::PopulationDensity() const {
  return double(population_) / land_area_;
}

std::vector<State> ReadStates(const std::string& csv_filename) {
  std::vector<State> states;
  std::vector<std::vector<std::string>> states_csv = ReadCSV(csv_filename, 48);

  for (int i = 1; i < states_csv.size() - 1; i++) {
    State state(states_csv[i][0], std::stoi(states_csv[i][2]),
                std::stod(states_csv[i][47]));
    states.push_back(state);
  }

  return states;
}
