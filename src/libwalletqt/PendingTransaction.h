#ifndef PENDINGTRANSACTION_H
#define PENDINGTRANSACTION_H

#include <QObject>

#include <wallet/wallet2_api.h>

//namespace Ferro {
//class PendingTransaction;
//}

class PendingTransaction : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Status status READ status)
    Q_PROPERTY(QString errorString READ errorString)
    Q_PROPERTY(quint64 amount READ amount)
    Q_PROPERTY(quint64 dust READ dust)
    Q_PROPERTY(quint64 fee READ fee)
    Q_PROPERTY(QStringList txid READ txid)
    Q_PROPERTY(quint64 txCount READ txCount)

public:
    enum Status {
        Status_Ok       = Ferro::PendingTransaction::Status_Ok,
        Status_Error    = Ferro::PendingTransaction::Status_Error,
        Status_Critical    = Ferro::PendingTransaction::Status_Critical
    };
    Q_ENUM(Status)

    enum Priority {
        Priority_Low    = Ferro::PendingTransaction::Priority_Low,
        Priority_Medium = Ferro::PendingTransaction::Priority_Medium,
        Priority_High   = Ferro::PendingTransaction::Priority_High
    };
    Q_ENUM(Priority)


    Status status() const;
    QString errorString() const;
    Q_INVOKABLE bool commit();
    quint64 amount() const;
    quint64 dust() const;
    quint64 fee() const;
    QStringList txid() const;
    quint64 txCount() const;
    Q_INVOKABLE void setFilename(const QString &fileName);

private:
    explicit PendingTransaction(Ferro::PendingTransaction * pt, QObject *parent = 0);

private:
    friend class Wallet;
    Ferro::PendingTransaction * m_pimpl;
    QString m_fileName;
};

#endif // PENDINGTRANSACTION_H
