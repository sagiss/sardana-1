//=============================================================================
//
// file :         PoolClass.h
//
// description :  Include for the PoolClass root class.
//                This class is represents the singleton class for
//                the Pool device class.
//                It contains all properties and methods which the 
//                Pool requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author$
//
// $Revision$
//
// $Log$
// Revision 1.32  2007/08/20 06:37:32  tcoutinho
// development commit
//
// Revision 1.31  2007/08/17 13:07:30  tcoutinho
// - pseudo motor restructure
// - pool base dev class restructure
// - initial commit for pseudo counters
//
// Revision 1.30  2007/07/30 11:00:59  tcoutinho
// Fix bug 5 : Additional information for controllers
//
// Revision 1.29  2007/07/04 15:06:38  tcoutinho
// first commit with stable Pool API
//
// Revision 1.28  2007/06/27 10:24:45  tcoutinho
// scond commit for comuncation channels. Added command/attribute skeleton with pogo
//
// Revision 1.27  2007/06/13 15:18:58  etaurel
// - Fix memory leak
//
// Revision 1.26  2007/05/11 08:07:48  tcoutinho
// - added new propertie to allow different sleep time in CounterTimer
// - added new property to allow sleep time in 0D experiment channel
//
// Revision 1.25  2007/04/23 15:23:06  tcoutinho
// - changes according to Sardana metting 26-03-2007: ActiveMeasurementGroup attribute became obsolete
//
// Revision 1.24  2007/02/06 09:41:03  tcoutinho
// - added MeasurementGroup
//
// Revision 1.23  2007/01/05 15:02:38  etaurel
// - First implementation of the Counter Timer class
//
// Revision 1.22  2006/11/07 14:57:09  etaurel
// - Now, the pool really supports different kind of controllers (cpp and py)
//
// Revision 1.21  2006/10/27 14:43:02  etaurel
// - New management of the MaxDevice stuff
// - SendToCtrl cmd added
// - Some bug fixed in prop management
//
// Revision 1.20  2006/10/06 13:29:01  tcoutinho
// changed info command names, added properties functionality
//
// Revision 1.19  2006/10/02 09:19:12  etaurel
// - Motor controller now supports extra features (both CPP and Python)
//
// Revision 1.18  2006/09/27 15:15:50  etaurel
// - ExternalFile and CtrlFile has been splitted in several classes:
//   ExternalFile, CppCtrlFile, PyExternalFile and PyCtrlFile
//
// Revision 1.17  2006/09/21 12:44:41  tcoutinho
// - python path changes
//
// Revision 1.16  2006/09/21 10:20:54  etaurel
// - The motor group do not ID any more
//
// Revision 1.15  2006/09/21 07:25:58  etaurel
// - Changes due to the removal of Motor ID in the Tango interface
//
// Revision 1.14  2006/09/20 15:59:01  tcoutinho
// pseudo motor API changed
//
// Revision 1.13  2006/09/20 13:11:12  etaurel
// - For the user point of view, the controller does not have ID any more.
// We are now using the controller instance name (uniq) to give them a name
//
// Revision 1.12  2006/09/18 12:33:05  etaurel
// - Fix some bug introduced in the merge in the PythonLock dtor
// - Some code beutifulling
//
// Revision 1.11  2006/09/18 10:32:22  etaurel
// - Commit after merge with pseudo-motor branch
//
// Revision 1.10  2006/07/07 12:38:43  etaurel
// - Some changes in file header
// - Commit after implementing the group multi motor read
//
// Revision 1.9  2006/06/15 15:36:31  etaurel
// - many changes after due to first test suite only on controller related stuff!!!
//
// Revision 1.8  2006/06/12 10:28:58  etaurel
// - Many changes dur to bug fixes found when writing test units...
//
// Revision 1.7  2006/05/25 09:13:47  etaurel
// - Stop Pool startup sequence in case Python LoadModule failed
// - Add logging possibility in the CtrlFiCa and CtrlFile classes
//
// Revision 1.6  2006/03/29 07:09:00  etaurel
// - Added motor group features
//
// Revision 1.5  2006/03/20 08:25:53  etaurel
// - Commit changes before changing the Motor interface
//
// Revision 1.4  2006/03/16 08:05:45  etaurel
// - Added code for the ControllerCode load and unload commands
// - Test and debug InnitController cmd with motor attached to the controller
//
// Revision 1.3  2006/03/14 14:54:10  etaurel
// - Again new changes in the internal structure
//
// Revision 1.2  2006/03/14 08:25:11  etaurel
// - Change the way objects are aorganized within the pool device
//
// Revision 1.1.1.1  2006/03/10 13:40:57  etaurel
// Initial import
//
// copyleft :     CELLS/ALBA
//				  Edifici Ciències Nord. Mòdul C-3 central.
//  			  Campus Universitari de Bellaterra. Universitat Autònoma de Barcelona
//  			  08193 Bellaterra, Barcelona
//  			  Spain
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#pragma once

#include "CtrlFile.h"
#include "CtrlFiCa.h"
#include "tango.h"
#include "Pool.h"
#include "PoolUtil.h"
#include "PyUtils.h"
#include "PyMotCtrlFile.h"


namespace Pool_ns
{
//=====================================
//	Define classes for attributes
//=====================================
class InstrumentListAttrib: public Tango::SpectrumAttr
{
public:
    InstrumentListAttrib():SpectrumAttr("InstrumentList", Tango::DEV_STRING, Tango::READ, 4096) {};
    ~InstrumentListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_InstrumentList(att);
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_InstrumentList_allowed(ty);}
};

class IORegisterListAttrib: public Tango::SpectrumAttr
{
public:
    IORegisterListAttrib():SpectrumAttr("IORegisterList", Tango::DEV_STRING, Tango::READ, 1024) {};
    ~IORegisterListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_IORegisterList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_IORegisterList_allowed(ty);}
};

class PseudoCounterListAttrib: public Tango::SpectrumAttr
{
public:
    PseudoCounterListAttrib():SpectrumAttr("PseudoCounterList", Tango::DEV_STRING, Tango::READ, 256) {};
    ~PseudoCounterListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_PseudoCounterList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_PseudoCounterList_allowed(ty);}
};

class ComChannelListAttrib: public Tango::SpectrumAttr
{
public:
    ComChannelListAttrib():SpectrumAttr("ComChannelList", Tango::DEV_STRING, Tango::READ, 1024) {};
    ~ComChannelListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_ComChannelList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_ComChannelList_allowed(ty);}
};

class PseudoMotorListAttrib: public Tango::SpectrumAttr
{
public:
    PseudoMotorListAttrib():SpectrumAttr("PseudoMotorList", Tango::DEV_STRING, Tango::READ, 256) {};
    ~PseudoMotorListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_PseudoMotorList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_PseudoMotorList_allowed(ty);}
};

class MotorListAttrib: public Tango::SpectrumAttr
{
public:
    MotorListAttrib():SpectrumAttr("MotorList", Tango::DEV_STRING, Tango::READ, 1024) {};
    ~MotorListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_MotorList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_MotorList_allowed(ty);}
};

class MotorGroupListAttrib: public Tango::SpectrumAttr
{
public:
    MotorGroupListAttrib():SpectrumAttr("MotorGroupList", Tango::DEV_STRING, Tango::READ, 256) {};
    ~MotorGroupListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_MotorGroupList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_MotorGroupList_allowed(ty);}
};

class MeasurementGroupListAttrib: public Tango::SpectrumAttr
{
public:
    MeasurementGroupListAttrib():SpectrumAttr("MeasurementGroupList", Tango::DEV_STRING, Tango::READ, 1024) {};
    ~MeasurementGroupListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_MeasurementGroupList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_MeasurementGroupList_allowed(ty);}
};

class ExpChannelListAttrib: public Tango::SpectrumAttr
{
public:
    ExpChannelListAttrib():SpectrumAttr("ExpChannelList", Tango::DEV_STRING, Tango::READ, 1024) {};
    ~ExpChannelListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_ExpChannelList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_ExpChannelList_allowed(ty);}
};

class ControllerListAttrib: public Tango::SpectrumAttr
{
public:
    ControllerListAttrib():SpectrumAttr("ControllerList", Tango::DEV_STRING, Tango::READ, 256) {};
    ~ControllerListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_ControllerList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_ControllerList_allowed(ty);}
};

class ControllerClassListAttrib: public Tango::SpectrumAttr
{
public:
    ControllerClassListAttrib():SpectrumAttr("ControllerClassList", Tango::DEV_STRING, Tango::READ, 256) {};
    ~ControllerClassListAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    { 
        try { 
            (static_cast<Pool *>(dev))->read_ControllerClassList(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_ControllerClassList_allowed(ty);}
};

class SimulationModeAttrib: public Tango::Attr
{
public:
    SimulationModeAttrib():Attr("SimulationMode", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
    ~SimulationModeAttrib() {};
    
    virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
    {   
        try { 
            (static_cast<Pool *>(dev))->read_SimulationMode(att);    
        } catch(Pool_ns::PoolFailed &pf) {
            Pool_ns::PoolTango::throw_tango_exception(pf);
        }
    }
    virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
    {(static_cast<Pool *>(dev))->write_SimulationMode(att);}
    virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
    {return (static_cast<Pool *>(dev))->is_SimulationMode_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
class DeleteIORegisterCmd : public Tango::Command
{
public:
    DeleteIORegisterCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeleteIORegisterCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeleteIORegisterCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeleteIORegister_allowed(any);}
};



class CreateIORegisterCmd : public Tango::Command
{
public:
    CreateIORegisterCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    CreateIORegisterCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~CreateIORegisterCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_CreateIORegister_allowed(any);}
};



class PutFileCmd : public Tango::Command
{
public:
    PutFileCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    PutFileCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~PutFileCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_PutFile_allowed(any);}
};



class GetFileClass : public Tango::Command
{
public:
    GetFileClass(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    GetFileClass(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~GetFileClass() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_GetFile_allowed(any);}
};



class DeletePseudoCounterCmd : public Tango::Command
{
public:
    DeletePseudoCounterCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeletePseudoCounterCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeletePseudoCounterCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeletePseudoCounter_allowed(any);}
};



class GetControllerInfoExCmd : public Tango::Command
{
public:
    GetControllerInfoExCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    GetControllerInfoExCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~GetControllerInfoExCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_GetControllerInfoEx_allowed(any);}
};



class DeleteComChannelCmd : public Tango::Command
{
public:
    DeleteComChannelCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeleteComChannelCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeleteComChannelCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeleteComChannel_allowed(any);}
};



class CreateComChannelCmd : public Tango::Command
{
public:
    CreateComChannelCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    CreateComChannelCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~CreateComChannelCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_CreateComChannel_allowed(any);}
};



class DeleteMeasurementGroupCmd : public Tango::Command
{
public:
    DeleteMeasurementGroupCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeleteMeasurementGroupCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeleteMeasurementGroupCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeleteMeasurementGroup_allowed(any);}
};



class CreateMeasurementGroupCmd : public Tango::Command
{
public:
    CreateMeasurementGroupCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    CreateMeasurementGroupCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~CreateMeasurementGroupCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_CreateMeasurementGroup_allowed(any);}
};



class SendToControllerCmd : public Tango::Command
{
public:
    SendToControllerCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    SendToControllerCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~SendToControllerCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_SendToController_allowed(any);}
};



class ReloadControllerCodeCmd : public Tango::Command
{
public:
    ReloadControllerCodeCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    ReloadControllerCodeCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~ReloadControllerCodeCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_ReloadControllerCode_allowed(any);}
};



class InitControllerCmd : public Tango::Command
{
public:
    InitControllerCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    InitControllerCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~InitControllerCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_InitController_allowed(any);}
};



class GetControllerInfoCmd : public Tango::Command
{
public:
    GetControllerInfoCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    GetControllerInfoCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~GetControllerInfoCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_GetControllerInfo_allowed(any);}
};



class DeletePseudoMotorClass : public Tango::Command
{
public:
    DeletePseudoMotorClass(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeletePseudoMotorClass(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeletePseudoMotorClass() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeletePseudoMotor_allowed(any);}
};



class DeleteMotorGroupCmd : public Tango::Command
{
public:
    DeleteMotorGroupCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeleteMotorGroupCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeleteMotorGroupCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeleteMotorGroup_allowed(any);}
};



class DeleteMotorCmd : public Tango::Command
{
public:
    DeleteMotorCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeleteMotorCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeleteMotorCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeleteMotor_allowed(any);}
};



class DeleteExpChannelCmd : public Tango::Command
{
public:
    DeleteExpChannelCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeleteExpChannelCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeleteExpChannelCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeleteExpChannel_allowed(any);}
};



class DeleteControllerCmd : public Tango::Command
{
public:
    DeleteControllerCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeleteControllerCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeleteControllerCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeleteController_allowed(any);}
};



class CreateMotorGroupCmd : public Tango::Command
{
public:
    CreateMotorGroupCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    CreateMotorGroupCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~CreateMotorGroupCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_CreateMotorGroup_allowed(any);}
};



class CreateMotorCmd : public Tango::Command
{
public:
    CreateMotorCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    CreateMotorCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~CreateMotorCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_CreateMotor_allowed(any);}
};



class CreateExpChannelCmd : public Tango::Command
{
public:
    CreateExpChannelCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    CreateExpChannelCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~CreateExpChannelCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_CreateExpChannel_allowed(any);}
};



class CreateControllerCmd : public Tango::Command
{
public:
    CreateControllerCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    CreateControllerCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~CreateControllerCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_CreateController_allowed(any);}
};



class CreateElementCmd : public Tango::Command
{
public:
    CreateElementCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    CreateElementCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~CreateElementCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_CreateElement_allowed(any);}
};



class DeleteElementCmd : public Tango::Command
{
public:
    DeleteElementCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    DeleteElementCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~DeleteElementCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_DeleteElement_allowed(any);}
};



class RenameElementCmd : public Tango::Command
{
public:
    RenameElementCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out,
                   const char        *in_desc,
                   const char        *out_desc,
                   Tango::DispLevel  level)
    :Command(name,in,out,in_desc,out_desc, level)	{};

    RenameElementCmd(const char   *name,
                   Tango::CmdArgType in,
                   Tango::CmdArgType out)
    :Command(name,in,out)	{};
    ~RenameElementCmd() {};
    
    virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
    virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
    {return (static_cast<Pool *>(dev))->is_RenameElement_allowed(any);}
};

//
// The PoolClass singleton definition
//

class PoolClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

    vector<CtrlFiCa *>			ctrl_ficas;
    vector<CtrlFile *>			ctrl_files;

    Pool* get_pool();

    vector<string> &get_pool_path();
    
    vct_ite get_ctrl_fica_by_name(string &, CtrlType );
    vct_ite add_ctrl_fica(string &,string &,string &,CtrlType,Pool *);
    void clear_ctrl_ficas();
    void print_all_fica_name();
    int32_t get_fica_nb_by_f_name(string &);
    int32_t get_fica_nb_by_name(string &);
    void remove_fica_by_name(string &);

    vcf_ite get_ctrl_file_by_name(const std::string &);
    vcf_ite add_ctrl_file(string &,CtrlType,Pool *);
    void clear_ctrl_files();
    void remove_ctrl_file_by_name(string &);
    void print_all_file_name();
    
    //CtrlType str_2_CtrlType(string &);

    Tango::DbData	cl_prop;
    Tango::DbData	cl_def_prop;
    Tango::DbData	dev_def_prop;

//	Method prototypes
    static PoolClass *init(const char *);
    static PoolClass *instance();
    ~PoolClass();
    Tango::DbDatum	get_class_property(string &);
    Tango::DbDatum	get_default_device_property(string &);
    Tango::DbDatum	get_default_class_property(string &);
    
protected:
    PoolClass(string &);
    static PoolClass *_instance;
    void command_factory();
    void get_class_property();
    void attribute_factory(vector<Tango::Attr *> &);
    void write_class_property();
    void set_default_property();

private:
    void device_factory(const Tango::DevVarStringArray *);
};

}	//	namespace Pool_ns
