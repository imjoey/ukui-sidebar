/*
* Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/

#ifndef SINGLEMSG_H
#define SINGLEMSG_H

#include <QWidget>
#include <QLabel>
#include <QDateTime>
#include <QToolButton>


class AppMsg;

class SingleMsg : public QWidget
{
    Q_OBJECT
public:
    SingleMsg(AppMsg* pParent, QString strIconPath, QString strAppName, QString strSummary, QDateTime dateTime, QString strBody, bool bTakeInFlag = false);
    void updatePushTime();
    void setTimeLabelVisible(bool bFlag);
    void setBodyLabelWordWrap(bool bFlag);
    uint getPushTime() {return m_uNotifyTime;}
    QDateTime getPushDateTime() {return m_dateTime;}
    QString getIcon() {return m_strIconPath;}
    QString getSummary() {return m_strSummary;}
    QString getBody() {return m_strBody;}
    bool getSingleDeleteButtonVisible() {return m_pSingleDeleteButton->isVisible();}
    void setLeftItem(int nShowLeftCount);
    void setMainFlag(bool bFlag) {m_bMain = bFlag;}
    void setFoldFlag(bool bFlag) {m_bFold = bFlag;}
    void setShowLeftItemFlag(bool bFlag);


protected:
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;

private:    
    QToolButton*    m_pIconToolButton;              //应用图标
    QLabel*         m_pAppNameLabel;                //保存应用名的Label
    QLabel*         m_pTimeLabel;
    QToolButton*    m_pSingleTakeinButton;          //单条消息中的收纳按钮
    QToolButton*    m_pSingleDeleteButton;          //单条消息中的删除按钮
    QLabel*         m_pBodyLabel;                   //正文标签
    QLabel*         m_pShowLeftItemLabel;           //显示该应用未展开条数


    QString         m_strIconPath;                  //图标路径
    QString         m_strAppName;                   //应用名
    QString         m_strSummary;                   //保存主题
    QString         m_strBody;                      //保存正文
    QString         m_strFormatBody;                //保存格式化后的正文
    QDateTime       m_dateTime;                     //保存推送时间
    uint            m_uNotifyTime;                  //保存推送时间的绝对时间
    bool            m_bTakeInFlag;                  //收纳标志
    bool            m_bFold;                        //是否折叠
    bool            m_bMain;                        //是否为主窗口
    int             m_nShowLeftCount;               //为主窗口时,剩余显示条数

signals:
    void            Sig_onDeleSingleMsg(SingleMsg* p);
    void            Sig_onTakeInSingleMsg(SingleMsg* p);
    void            Sig_onDeleteAppMsg();
    void            Sig_setAppFoldFlag(bool bFoldFlag);

public slots:
    void            onDele();
    void            onTakeIn();

};

#endif // SINGLEMSG_H
