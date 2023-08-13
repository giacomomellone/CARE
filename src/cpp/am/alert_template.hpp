#pragma once

#include <string>

class AlertTemplate
{
public:
	AlertTemplate(const std::string &title_template, const std::string &body_template, int severityLevel)
		: _title_template(title_template), _body_template(body_template), _severity(severityLevel) {}

	~AlertTemplate() {}

	std::string get_title() const
	{
		return _title_template;
	}

	std::string getBody() const
	{
		return _body_template;
	}

	int get_severity() const
	{
		return _severity;
	}

	std::string format_title(const std::string &location) const
	{
		return "Location: " + location + " - " + _title_template;
	}

	std::string format_body(const std::string &details) const
	{
		return _body_template + "\nDetails: " + details;
	}

private:
	std::string _title_template;
	std::string _body_template;
	int _severity;
};
