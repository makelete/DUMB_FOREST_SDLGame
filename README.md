# DUMB_FOREST

Giới thiệu:


    - Họ và tên: Bùi Đức Duy

    - Mã sinh viên: 22021201

    - Khóa học: QH-2022-I/CQ-C-B

    - Lớp học phần: INT2215 1

===========================================================================

Game:


    1, Tên: DUMB_FOREST - Là dự án game do Bùi Đức Duy phát triển dựa trên ngôn ngữ C++ và thư viện SDL2.


    2, Nội dung dự án:


        - Bối cảnh: Một buổi đêm nọ tại vùng đất Fuslooc yên bình, khi mọi người đang chìm trong giấc ngủ,
        một viên thiên thạch đã bất ngời rơi vào khu rừng gần đó gây chấn động tới toàn bộ người dân Fuslooc.
        Sau đêm đó, dường như mọi thứ đều trở nên khác lạ, từ đất đai, cây cối, động vật thậm chí là cả
        con người. Trong đó Moc và Meo là 2 người xấu số bị biến đổi:

                + Moc: Từ 1 thanh niên vạm vỡ trong làng thành một thổ dân da vàng với chiếc mặt nạ gắn 
                liền trên khuôn mặt.

                + Meo: Từ 1 cô gái xinh đẹp thành ninja ếch xanh.

            Vì thế, 2 người bị dân làng kỳ thị để rồi họ bị đuổi vào khu rừng - nơi bắt nguồn của mọi thứ.
        Nhiệm vụ của các bạn là giúp họ sống sót vượt qua khu rừng bằng cách vượt chướng ngại vật, thu 
        thập cá để có thức ăn và tiến tới cánh cổng dịch chuyển.


        - Khu rừng gồm có 2 màn với địa hình khác nhau.


        - Chướng ngại vật gồm có:

            + Lava: Lava sẽ chỉ cản trở được Meo (ninja ếch xanh) chứ không ảnh hưởng tới Moc (thổ dân mặt nạ).

            + GreenLiquid: Vũng nước acid màu xanh lá này sẽ chỉ cản trở Moc (thổ dân mặt nạ) chứ không ảnh 
            hưởng tới Meo (ninja ếc xanh).

            + Poison: Vũng nước màu đen này sẽ cản trở cả 2 nhân vật.

            ***Lưu ý: Các bạn sẽ phải bắt đầu lại nếu như bị cản trở bởi ít nhất 1 trong 3 chướng ngại vật trên.


        - Các mục tiêu trên cao:

            + Cá vàng: Loại cá này sẽ giúp Moc (thổ dân mặt nạ) kiếm thêm điểm (+5) nếu anh ta ăn nó, nhưng 
            lại khiến Meo (ninja ếch xanh) bị trừ điểm (-10) nếu cô ta dính phải. Chúng sẽ biến mất khi bị 
            bất cứ ai chạm vào.

            + Cá xanh: Loại cá này sẽ giúp Meo (ninja xanh lá) kiếm thêm điểm (+5) nếu cô ta ăn nó, nhưng 
            lại khiến Moc (thổ dân mặt nạ) bị trừ điểm (-10) nếu anh ấy dính phải. Chúng sẽ biến mật khi bị
            bất cứ ai chạm vào.


        - Nấm: Đây là đồng minh, Nấm sẽ giúp cho Moc và Meo nhảy cao hơn, giúp cho họ dễ dàng hơn trên con 
        đường đi tới cổng dịch chuyển.


        - Cổng dịch chuyển: Nó sẽ giúp các bạn chuyển màn nếu như đang ở màn 1 và sẽ chiến thắng nếu như các
        bạn dã tới màn 2. Yêu cầu cả hai nhân vật đều phải có mặt tại cổng thì cánh cổng mới hoạt động.

===========================================================================

Cách cài đặt game:

        
   - B1: Clone repository này về máy.

   - B2: Chạy các dòng lệnh sau trong terminal:
            
            mingw32-make DUMB_FOREST.exe

===========================================================================

Xin cảm ơn mọi người đã quan tâm. Mọi thắc mắc xin liên hệ: 22021201@vnu.edu.vn