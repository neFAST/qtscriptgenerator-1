/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Script Generator project on Qt Labs.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef REPORTHANDLER_H
#define REPORTHANDLER_H

#include <QtCore/QString>
#include <QtCore/QSet>

class ReportHandler
{
public:
    enum DebugLevel { NoDebug, SparseDebug, MediumDebug, FullDebug };

    static void setContext(const QString &context) { m_context = context; }

    static DebugLevel debugLevel() { return m_debug_level; }
    static void setDebugLevel(DebugLevel level) { m_debug_level = level; }

    static int warningCount() { return m_warning_count; }

    static int suppressedCount() { return m_suppressed_count; }

    static void warning(const QString &str);

    static void debugSparse(const QString &str) {
        debug(SparseDebug, str);
    }
    static void debugMedium(const QString &str) {
        debug(MediumDebug, str);
    }
    static void debugFull(const QString &str) {
        debug(FullDebug, str);
    }
    static void debug(DebugLevel level, const QString &str);

private:
    static int m_warning_count;
    static int m_suppressed_count;
    static DebugLevel m_debug_level;
    static QString m_context;
    static QSet<QString> m_reported_warnings;
};

#endif // REPORTHANDLER_H
