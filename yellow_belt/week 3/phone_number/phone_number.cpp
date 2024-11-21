#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>

#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number){
  	if (international_number[0] != '+')
      throw invalid_argument("+");

    stringstream stream(international_number);
    stream.ignore(1);
    getline(stream, country_code_, '-');
    getline(stream, city_code_, '-');
    getline(stream, local_number_);

    if (country_code_.empty() || city_code_.empty() || local_number_.empty())
      throw invalid_argument("empty code");
}

string PhoneNumber::GetCountryCode() const{
  return country_code_;
}

string PhoneNumber::GetCityCode() const{
  return city_code_;
}

string PhoneNumber::GetLocalNumber() const{
  return local_number_;
}

string PhoneNumber::GetInternationalNumber() const{
  return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
