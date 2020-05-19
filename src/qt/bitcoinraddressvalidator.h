// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINR_QT_BITCOINRADDRESSVALIDATOR_H
#define BITCOINR_QT_BITCOINRADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class bitcoinRAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit bitcoinRAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** bitcoinR address widget validator, checks for a valid bitcoinr address.
 */
class bitcoinRAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit bitcoinRAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BITCOINR_QT_BITCOINRADDRESSVALIDATOR_H
