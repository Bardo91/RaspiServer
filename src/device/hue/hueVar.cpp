//----------------------------------------------------------------------------------------------------------------------
// Project: Domocracy, dmcLib
// Author: Carmelo J. Fdez-Agüera Tortosa (a.k.a. Technik)
// Date: 2014-Dec-24
//----------------------------------------------------------------------------------------------------------------------
// weak data object to store responses from hue bridge
#include <cassert>
#include "hueVar.h"
#include <utility>

using namespace std;

namespace dmc {

	namespace {
		const char separtors[] = " \t\r\n";
	}

	//------------------------------------------------------------------------------------------------------------------
	HueVar::HueVar(const string& _code) {
		initWithCode(_code);
	}

	//------------------------------------------------------------------------------------------------------------------
	unsigned HueVar::initWithCode(const string& _code) {
		unsigned cursor = _code.find_first_of("[{\"0123456789");
		assert(string::npos != cursor); // Code must be valid

		if('\"' == _code[cursor]) { // Text literal
			unsigned terminator = _code.find_first_not_of(separtors, cursor+1);
			mString = _code.substr(cursor+1,terminator);
			mType = DataType::text;
			return terminator;
		} else if('[' == _code[cursor]) {
			mType = DataType::list;
			cursor = _code.find_first_not_of(separtors, cursor+1);
			while(_code[cursor] != ']') {
				mList.push_back(HueVar());
				HueVar& element = mList.back();
				cursor += element.initWithCode(_code.substr(cursor));
			}
			return cursor;
		} else if('{' == _code[cursor]) {
			mType = DataType::dictionary;
			cursor = _code.find_first_not_of(separtors, cursor+1);
			while(_code[cursor] != '}') {
				assert(_code[cursor] == '\"'); // Key stored as a string
				unsigned terminator = _code.find('\"', cursor+1);
				auto element = make_pair(_code.substr(cursor+1,terminator), HueVar());
				unsigned separator = _code.find(':', terminator+1);
				cursor = 1+ separator + element.second.initWithCode(_code.substr(separator+1));
			}
			return cursor;
		} else { // number
			unsigned terminator = _code.find_first_not_of("0123456789", cursor+1);
			mType = DataType::integer;
			mInt = atoi(_code.c_str());
			return terminator;
		}
	}

}	// namespace dmc