//
// Created by jradi on 10/30/2019.
//

#include <sstream>
#include "rule.h"
#include "evaluation/rules/wrapper_rule.h"

int rule::get_start_state() const {
	return start_state;
}

int rule::get_end_state() const {
	return end_state;
}

bool rule::is_force_occur() const {
	return force_occur;
}

rule::rule(int start_state, int end_state, bool force_occur) : start_state(start_state), end_state(end_state),
															   force_occur(force_occur) {}

wrapper_rule *rule::to_wrapper_rule(int new_start, int new_end) {
	return new wrapper_rule(new_start, new_end, force_occur, this);
}

std::string rule::match_reason() const{
	return "unknown";
}

std::string rule::to_string() const{
	
	
	return std::to_string(start_state) + " on " + match_reason() + " -> "
	+ std::to_string(end_state);
}
