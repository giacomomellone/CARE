#pragma once

#include <string>

class RiskData
{
public:
	RiskData(double risk_value, const std::string &location, const std::string &details)
		: risk_value(risk_value), location(location), details(details) {}

	double get_risk_value() const { return risk_value; }
	const std::string &get_location() const { return location; }
	const std::string &get_details() const { return details; }

private:
	double risk_value;	  // The value representing the risk level
	std::string location; // The location associated with the risk data
	std::string details;  // Additional details or description
};
