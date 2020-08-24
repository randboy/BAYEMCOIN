// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017 The Ravencoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BAYEMCOIN_QT_BAYEMCOINADDRESSVALIDATOR_H
#define BAYEMCOIN_QT_BAYEMCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BayemcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BayemcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Bayemcoin address widget validator, checks for a valid bayemcoin address.
 */
class BayemcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BayemcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BAYEMCOIN_QT_BAYEMCOINADDRESSVALIDATOR_H
