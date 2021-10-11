#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "PIQueue.h"

void xepHang(int soLuongKhach, int tgDen_AVG, Queue *Q)
{
    int stt;
    makenullQueue(Q);
    for (stt = 1; stt <= soLuongKhach; stt++)
    {
        enQueue(stt * tgDen_AVG, Q);
    }
}

int soQuayPhaiMo(int soKhachHang, int soQuayMax, int tg_xl_tb, int tg_tb_khachDen, int tg_gioiHan, float *tg_tb_cuaMoiKhachHang)
{
    Queue Q;
    //khai bao thoi gian tong, thoi diem di va thoi diem den cua tung khach hang, va so luong quay phai mo
    int sumTime, thoiDiem_di, thoiDiem_den, soQuayMo;

    int time_khachTruoc_di[soQuayMax];
    int i; //i dong vai tro nhu so thu tu quay

    *tg_tb_cuaMoiKhachHang = tg_gioiHan + 1; //khoi dau cho thoi gian trung binh > thoi gian muc tieu, de khi thuc hien vong lap, muc tieu can co la thoi gian trung binh nho hon thoi gian muc tieu

    soQuayMo = 1; //khoi dau bang 1 quay mo

    while (soQuayMo <= soQuayMax && *tg_tb_cuaMoiKhachHang > tg_gioiHan)
    {

        //khoi tao thoi diem di cua cua khach hang truoc o tat ca cac quay duoc mo bang 0
        for (i = 1; i <= soQuayMo; i++)
        {
            time_khachTruoc_di[i - 1] = 0; //i-1 la tai quay dang xet
        }

        xepHang(soKhachHang, tg_tb_khachDen, &Q);

        sumTime = 0;
        while (!emptyQueue(Q))
        { //duyet qua tung khach hang
            for (i = 1; i <= soQuayMo && !emptyQueue(Q); i++)
            {
                thoiDiem_den = front(Q); //thoi diem den cua khach hang la phan tu dau ngan xep
                deQueue(&Q);             //sau khi lay duoc thoi diem den, thi xoa phan tu dau ngan xep

                if (thoiDiem_den >= time_khachTruoc_di[i - 1])
                {
                    thoiDiem_di = thoiDiem_den + tg_xl_tb;
                }
                else
                    thoiDiem_di = time_khachTruoc_di[i - 1] + tg_xl_tb;

                time_khachTruoc_di[i - 1] = thoiDiem_di; //cap nhat lai thoi diem di cua khach hang dang xet se bang thoi diem di cua khach hang nay

                sumTime = sumTime + (thoiDiem_di - thoiDiem_den); //thoiDiem_di - thoiDiem_den chinh la thoi gian thanh toan cua khach hang
            }
        }

        *tg_tb_cuaMoiKhachHang = sumTime / soKhachHang;

        if (*tg_tb_cuaMoiKhachHang > tg_gioiHan)
        {
            printf("So quay: %d; ", soQuayMo);
            printf("Thoi gian cho trung binh: %.1f\n", *tg_tb_cuaMoiKhachHang);
        }
        soQuayMo++; //mo them mot quay
    }
    return soQuayMo - 1;
}

int main()
{
    int sokhach, quayToiDa, time_xl_tb, time_tb_xephang, time_mucTieu;
    float tg_tb;
    scanf(
        "%d%d%d%d%d",
        &sokhach,
        &quayToiDa,
        &time_xl_tb,
        &time_tb_xephang,
        &time_mucTieu);

    int soquayMo = soQuayPhaiMo(sokhach, quayToiDa, time_xl_tb, time_tb_xephang, time_mucTieu, &tg_tb);

    if (tg_tb <= time_mucTieu)
    {
        printf("So quay: %d; ", soquayMo);
        printf("Thoi gian cho trung binh: %.1f\n", tg_tb);
        printf("=> Sieu thi se mo %d quay", soquayMo);
    }
    else
        printf("Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.", soquayMo, tg_tb);
    return 0;
}
