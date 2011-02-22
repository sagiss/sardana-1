//+=============================================================================
//
// file :         Controller.cpp
//
// description :  C++ source for the Controller and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                Controller are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



//===================================================================
//
//	The following table gives the correspondence
//	between commands and method name.
//
//  Command name   |  Method name
//	----------------------------------------
//  State          |  dev_state()
//  Status         |  dev_status()
//  AddElement     |  add_element()
//  DeleteElement  |  delete_element()
//  Send           |  send()
//
//===================================================================


#include <tango.h>
#include "Controller.h"
#include "ControllerClass.h"

namespace Controller_ns
{

//+----------------------------------------------------------------------------
//
// method : 		Controller::Controller(string &s)
// 
// description : 	constructor for simulated Controller
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name 
//
//-----------------------------------------------------------------------------
Controller::Controller(Tango::DeviceClass *cl,string &s)
:Tango::Device_4Impl(cl,s.c_str())
{
    init_device();
}

Controller::Controller(Tango::DeviceClass *cl,const char *s)
:Tango::Device_4Impl(cl,s)
{
    init_device();
}

Controller::Controller(Tango::DeviceClass *cl,const char *s,const char *d)
:Tango::Device_4Impl(cl,s,d)
{
    init_device();
}
//+----------------------------------------------------------------------------
//
// method : 		Controller::delete_device()
// 
// description : 	will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------
void Controller::delete_device()
{
    //	Delete device's allocated object
}

//+----------------------------------------------------------------------------
//
// method : 		Controller::init_device()
// 
// description : 	will be called at device initialization.
//
//-----------------------------------------------------------------------------
void Controller::init_device()
{
    INFO_STREAM << "Controller::Controller() create device " << device_name << endl;

    // Initialise variables to default values
    //--------------------------------------------
}

//+----------------------------------------------------------------------------
//
// method : 		Controller::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void Controller::always_executed_hook()
{
    
}
//+----------------------------------------------------------------------------
//
// method : 		Controller::read_attr_hardware
// 
// description : 	Hardware acquisition for attributes.
//
//-----------------------------------------------------------------------------
void Controller::read_attr_hardware(vector<long> &attr_list)
{
    DEBUG_STREAM << "Controller::read_attr_hardware(vector<long> &attr_list) entering... "<< endl;
    //	Add your own code here
}

//+----------------------------------------------------------------------------
//
// method : 		Controller::read_Elements
// 
// description : 	Extract real attribute values for Elements acquisition result.
//
//-----------------------------------------------------------------------------
void Controller::read_Elements(Tango::Attribute &attr)
{
    DEBUG_STREAM << "Controller::read_Elements(Tango::Attribute &attr) entering... "<< endl;
}



//+------------------------------------------------------------------
/**
 *	method:	Controller::add_element
 *
 *	description:	method to execute "AddElement"
 *	adds a new axis to the controller. This will translate in creating a new tango device of the
 *	class this controller type is.
 *
 * @param	argin	arg[0] - axis number (starting at 1)\narg[1] - element name\narg[2] - (optional) device name
 *
 */
//+------------------------------------------------------------------
void Controller::add_element(const Tango::DevVarStringArray *argin)
{
    DEBUG_STREAM << "Controller::add_element(): entering... !" << endl;

    //	Add your own code to control device here

}

//+------------------------------------------------------------------
/**
 *	method:	Controller::delete_element
 *
 *	description:	method to execute "DeleteElement"
 *	Removes the axis given as parameter for this controller
 *
 * @param	argin	the axis number or element name or device name
 *
 */
//+------------------------------------------------------------------
void Controller::delete_element(Tango::DevString argin)
{
    DEBUG_STREAM << "Controller::delete_element(): entering... !" << endl;

    //	Add your own code to control device here

}


//+------------------------------------------------------------------
/**
 *	method:	Controller::send
 *
 *	description:	method to execute "Send"
 *	Sends a string of characters to the controller
 *
 * @param	argin	The string to send to the controller
 * @return	The response from the controller
 *
 */
//+------------------------------------------------------------------
Tango::DevVarCharArray *Controller::send(const Tango::DevVarCharArray *argin)
{
    //	POGO has generated a method core with argout allocation.
    //	If you would like to use a static reference without copying,
    //	See "TANGO Device Server Programmer's Manual"
    //		(chapter : Writing a TANGO DS / Exchanging data)
    //------------------------------------------------------------
    Tango::DevVarCharArray	*argout  = new Tango::DevVarCharArray();
    argout->length(1);
    (*argout)[0] = 0;
    DEBUG_STREAM << "Controller::send(): entering... !" << endl;

    //	Add your own code to control device here

    return argout;
}

}	//	namespace