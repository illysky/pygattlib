// -*- mode: c++; coding: utf-8; tab-width: 4 -*-

// Copyright (C) 2014, Oscar Acena <oscaracena@gmail.com>
// This software is under the terms of Apache License v2 or later.

#ifndef _GATTSERVICES_H_
#define _GATTSERVICES_H_

#include <boost/python/dict.hpp>
#include <map>

#define EIR_FLAGS          			0x01
#define EIR_16BIT_UUIDS_INCOMPLETE 	0x02
#define EIR_16BIT_UUIDS_COMPLETE 	0x03
#define EIR_32BIT_UUIDS_INCOMPLETE	0x04
#define EIR_32BIT_UUIDS_COMPLETE 	0x05
#define EIR_128BIT_UUIDS_INCOMPLETE	0x06
#define EIR_128BIT_UUIDS_COMPLETE 	0x07
#define EIR_NAME_SHORT     			0x08  /* shortened local name */
#define EIR_NAME_COMPLETE  			0x09  /* complete local name */
/* ... */
#define EIR_APPEARANCE 				0x19

#define BLE_EVENT_TYPE     			0x05
#define BLE_SCAN_RESPONSE  			0x04

class DiscoveryService {
public:
	DiscoveryService(const std::string device="hci0");
	virtual ~DiscoveryService();
	boost::python::dict discover(int timeout);


protected:
	void enable_scan_mode();
	void get_advertisements(int timeout, boost::python::dict & ret);
	virtual void process_input(unsigned char* buffer, int size,
			boost::python::dict & ret);

	int parse_flags(uint8_t* data, size_t size);
	std::string parse_name(uint8_t* data, size_t size);
	boost::python::list parse_uuids(uint8_t* data, size_t size);
	int parse_appearance(uint8_t* data, size_t size);

	void disable_scan_mode();

	std::string _device;
	int _device_desc;
	int _timeout;
};

#endif // _GATTSERVICES_H_
