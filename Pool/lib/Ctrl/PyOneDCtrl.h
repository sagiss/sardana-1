#ifndef _PYONEDCTRL_H
#define _PYONEDCTRL_H

#include "PyCtrl.h"
#include <tango.h>
#include <pool/OneDCtrl.h>

extern "C"
{
    Controller *_create_PyOneDExpChannelController(const char *,const char *,PyObject *,PyObject *);
}

/**
 * The Python 1D experiment channel controller base class
 */
class PyOneDController:public PyController,public OneDController
{
public:
    PyOneDController(const char *,const char *,PyObject *,PyObject *);
    ~PyOneDController();

    virtual void AddDevice(int32_t idx);
    virtual void DeleteDevice(int32_t idx);
        
    virtual void PreReadAll();
    virtual void PreReadOne(int32_t);
    virtual void ReadAll();
    virtual double *ReadOne(int32_t);
    
    virtual void PreStateAll();
    virtual void PreStateOne(int32_t);
    virtual void StateAll();
    virtual void StateOne(int32_t, Controller::CtrlState *);

    virtual void StartOne(int32_t);
    
    virtual Controller::CtrlData GetPar(int32_t,std::string &);
    virtual void SetPar(int32_t,std::string &,Controller::CtrlData &);

    virtual std::string SendToCtrl(std::string &);
    
    virtual void SetExtraAttributePar(int32_t,std::string &,Controller::CtrlData &);
    virtual Controller::CtrlData GetExtraAttributePar(int32_t,std::string &);
                
protected:
    void clear_method_flag();
    void check_existing_methods(PyObject *);
    
    bool		pre_read_all;
    bool		pre_read_one;
    bool		read_all;
    
    bool		abort_one;
    bool		start_one;
    bool		set_par;
    bool		get_par;
    
};

typedef Controller *(*PyCtrl_creator_ptr)(const char *,const char *,PyObject *,PyObject *);

#endif /* _PYONEDCTRL_H */