/*
 * Copyright (C) 2017 Chupligin Sergey <neochapay@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "settings.h"

#include <QSettings>

Settings::Settings(QObject *parent) : QObject(parent)
{
    m_settings = new QSettings();
}

Settings::~Settings()
{
}


void Settings::setValue(const QString &key, const QVariant &value)
{
    m_settings->setValue(key, value);
    emit valueChanged(key, value);
}

QVariant Settings::value(const QString &key, const QVariant &defaultValue)
{
    return m_settings->value(key, defaultValue);
}

void Settings::sync()
{
    m_settings->sync();
}
