/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * HandlerWebService.h - _explain_
 *
 * Copyright (C) 2011 ezlibs.com, All Rights Reserved.
 *
 * $Id: HandlerWebService.h 5884 2013-01-29 03:21:04Z WuJunjie $
 *
 *  Explain:
 *     -explain-
 *
 *  Update:
 *     2013-01-29 03:21:04  Create
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

#ifndef _HandlerWebService_H
#define _HandlerWebService_H

#include <SocketHandler.h>

#include <SocketHandler.h>
#include <TcpSocket.h>
#include <map>

#include "Session.h"

#include "HttpServerWebService.h"

#include "../DoubleOutLog.h"

class CHandlerWebService : public SocketHandler
{
public:
    CHandlerWebService(CDoubleOutLog *pLog=NULL);

    void tprintf(TcpSocket *,const char *format, ...);
    void List(TcpSocket *);
    void Update();

    Socket *GetSocketByName(std::string strServerName);

    Socket *GetSocketBySessionID(std::string strSessionID);

    // ����֤
    int newSession(const CSession &newss);

    // ��Ȩ
    int AuthSession(std::string strSession, int iAccessId=0);

private:
    // strSessionId
    CSessionManager m_requestSession;
};

#endif // _HandlerWebService_H
