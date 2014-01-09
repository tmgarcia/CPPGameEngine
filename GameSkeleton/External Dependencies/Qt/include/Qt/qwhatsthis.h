/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QWHATSTHIS_H
#define QWHATSTHIS_H

#include <QtCore/qobject.h>
#include <QtGui/qcursor.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

#ifndef QT_NO_WHATSTHIS

class QAction;
#ifdef QT3_SUPPORT
class QToolButton;
#endif

class Q_GUI_EXPORT QWhatsThis
{
    QWhatsThis();

public:
    static void enterWhatsThisMode();
    static bool inWhatsThisMode();
    static void leaveWhatsThisMode();

    static void showText(const QPoint &pos, const QString &text, QWidget *w = 0);
    static void hideText();

    static QAction *createAction(QObject *parent = 0);

#ifdef QT3_SUPPORT
    static QT3_SUPPORT void add(QWidget *w, const QString &s);
    static QT3_SUPPORT void remove(QWidget *);
    static QT3_SUPPORT QToolButton *whatsThisButton(QWidget *parent);
#endif
};

#endif // QT_NO_WHATSTHIS

QT_END_NAMESPACE

QT_END_HEADER

#endif // QWHATSTHIS_H
