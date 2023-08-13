#pragma once

#include "risk_data.hpp"

class AlertCriteria
{
public:
	AlertCriteria(double threshold, int severity) : _threshold(threshold), _severity(severity) {}
	~AlertCriteria() {}

	bool meets_criteria(const RiskData &data) const
	{
		return data.get_risk_value() >= _threshold;
	}

	int get_severity() const
	{
		return _severity;
	}

private:
	double _threshold;
	int _severity;
};
