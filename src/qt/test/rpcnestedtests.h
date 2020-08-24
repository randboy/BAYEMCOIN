// Copyright (c) 2016 The Bitcoin Core developers
// Copyright (c) 2017 The Ravencoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BAYEMCOIN_QT_TEST_RPC_NESTED_TESTS_H
#define BAYEMCOIN_QT_TEST_RPC_NESTED_TESTS_H

#include <QObject>
#include <QTest>

#include "txdb.h"
#include "txmempool.h"

class RPCNestedTests : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
    void rpcNestedTests();

private:
    CCoinsViewDB *pcoinsdbview;
};

#endif // BAYEMCOIN_QT_TEST_RPC_NESTED_TESTS_H
