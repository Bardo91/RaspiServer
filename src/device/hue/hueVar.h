//----------------------------------------------------------------------------------------------------------------------
// Project: Domocracy, dmcLib
// Author: Carmelo J. Fdez-Agüera Tortosa (a.k.a. Technik)
// Date: 2014-Dec-22
//----------------------------------------------------------------------------------------------------------------------
// weak data object to store responses from hue bridge
#ifndef _DMCSERVER_DEVICE_HUE_HUEVAR_H_
#define _DMCSERVER_DEVICE_HUE_HUEVAR_H_

#include <unordered_map>
#include <string>
#inckyde <vector>

namespace dmc {
	class HueVar {
	public:
		// Construction and asignment
		explicit HueVar(const std::string _code);
		HueVar(const HueVar&);
		HueVar& operator=(const HueVar&);

		void setFromCode(const std::string& _code);

		// Type deduction
		bool isNill			() const { return mType == DataType::nill; }
		bool isInt			() const { return mType == DataType::integer; }
		bool isText			() const { return mType == DataType::text; }
		bool isDictionary	() const { return mType == DataType::dictionary; }
		bool isList			() const { return mType == DataType::list; }

		// Simple getters and setters
		int&				asInt		();
		int					asInt		() const;
		void				setInt		(int);
		std::string&		asText		();
		const std::string&	asText		() const;
		void				setText		(const std::string&);

		// Dictionary accessors
		HueVar&				operator[]	(const std::string& _key);
		const HueVar&		operator[]	(const std::string& _key) const;
		// List accessors
		HueVar&				operator[]	(unsigned _idx);
		const HueVar&		operator[]	(unsigned _idx) const;

	private:
		typedef std::unordered_map<std::string, HueVar>	Dictionary;
		typedef std::vector<HueVar>	List;

		enum class DataType {
			nill,
			integer,
			text,
			dictionary,
			list
		} mType;

		std::string mString;
		int			mInt;
		Dictionary	mDictionary;
		List		mList;
	};
}

#endif // _DMCSERVER_DEVICE_HUE_HUEVAR_H_