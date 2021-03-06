/*
 * This file is part of KSysGuard.
 * Copyright 2019 Arjen Hiemstra <ahiemstra@heimr.nl>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONNECTIONMAPPING_H
#define CONNECTIONMAPPING_H

#include <unordered_map>
#include <unordered_set>
#include <regex>

// #include <QRegularExpression>

#include "Packet.h"

/**
 * @todo write docs
 */
class ConnectionMapping
{
public:
    struct PacketResult {
        int pid = 0;
        Packet::Direction direction;
    };

    ConnectionMapping();

    void parseProc();

    PacketResult pidForPacket(const Packet &packet);

private:
    bool parseSockets();
    void parsePid();
    void parseSocketFile(const char* fileName);

    std::unordered_map<Packet::Address, int> m_localToINode;
    std::unordered_map<int, int> m_inodeToPid;
    std::unordered_set<int> m_inodes;
    std::unordered_set<int> m_pids;

//     QRegularExpression m_socketFileMatch;
    std::regex m_socketFileMatch;
};

#endif // CONNECTIONMAPPING_H
