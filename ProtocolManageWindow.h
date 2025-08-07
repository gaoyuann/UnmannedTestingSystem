#ifndef PROTOCOLMANAGEWINDOW_H
#define PROTOCOLMANAGEWINDOW_H

#include <QWidget>
#include <QVector>
#include <QStringList>
#include <QStyledItemDelegate>
#include <QPainter>

namespace Ui {
class ProtocolManageWindow;
}

struct MessageFormat;

class CheckBoxDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        painter->save();
        painter->setRenderHint(QPainter::Antialiasing, true);

        if (opt.state & QStyle::State_MouseOver) {
            painter->fillRect(opt.rect.adjusted(1,1,-1,-1), QColor(220, 230, 240));
        }

        QRect checkRect = QRect(opt.rect.x() + opt.rect.width()/2 - 8,
                                opt.rect.y() + opt.rect.height()/2 - 8,
                                16, 16);

        bool checked = index.data(Qt::CheckStateRole) == Qt::Checked;
        QColor checkColor = checked ? QColor(58, 110, 165) : QColor(200, 200, 200);

        painter->setPen(QPen(checkColor, 1.5));
        painter->setBrush(checked ? QBrush(checkColor) : QBrush(Qt::white));
        painter->drawRoundedRect(checkRect, 3, 3);

        if (checked) {
            painter->setPen(QPen(Qt::white, 2));
            painter->drawLine(checkRect.x()+4, checkRect.y()+8,
                              checkRect.x()+6, checkRect.y()+12);
            painter->drawLine(checkRect.x()+6, checkRect.y()+12,
                              checkRect.x()+12, checkRect.y()+4);
        }

        painter->restore();
    }
};

class ProtocolManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProtocolManageWindow(QWidget *parent = nullptr);
    ~ProtocolManageWindow();

signals:
    void statusMessageRequested(const QString &message, int timeout = 0);

private slots:
    void onAdd();
    void onEdit();
    void onDelete();
    void onFormat();
    void onSearch();
    void onProtocolSelected(int row);
    void onPageChanged(int index);
    void onPageSizeChanged(int index);
    void gotoFirstPage();
    void gotoPrevPage();
    void gotoNextPage();
    void gotoLastPage();

private:
    void initUI();
    void initPagination();
    void setupConnections();
    QVector<QStringList> getAllProtocols();
    bool addProtocol(const QStringList &protocolData);
    bool updateProtocol(int protocolId, const QStringList &protocolData);
    bool deleteProtocols(const QList<int> &protocolIds);
    QVector<QStringList> searchProtocols(const QString &keyword);
    QVector<MessageFormat> getMessageFormats(int protocolId);
    bool saveMessageFormats(int protocolId, const QVector<MessageFormat> &formats);
    void updatePagination();
    void updateProtocolTable();
    QList<int> getSelectedRows() const;
    void updateTableWithResults(const QVector<QStringList> &results);

    Ui::ProtocolManageWindow *ui;
    int currentPage;
    int pageSize;
    int totalPages;
    int currentProtocolId;
};

#endif // PROTOCOLMANAGEWINDOW_H
