*This project has been created as part of the 42 curriculum by ademirel, mcodel.*

## Açıklama (Description)
Push_swap, sınırlı bir talimat seti kullanarak ve mümkün olan en az sayıda hamle ile iki yığın (`stack a` ve `stack b`) üzerindeki verileri sıralamayı amaçlayan bir algoritma projesidir. Bu proje, algoritmik karmaşıklığı teorik bir kavramdan ziyade, operasyon sayısı üzerinden somut bir şekilde kavramayı hedefler.

## Katkılar
Proje, her iki ekip üyesinin de algoritmaları tam olarak anladığı ve koda hakim olduğu bir iş birliğiyle tamamlanmıştır.
* **ademirel**: Veri ayrıştırıcı (parser), zorunlu hata yönetimi, "Disorder" (Düzensizlik) metriği hesaplama motoru, Basit ($O(n^2)$) algoritma ve Adaptif seçim mantığının geliştirilmesi.
* **mcodel**: Orta ($O(n√n)$) ve Karmaşık ($O(nlogn)$) algoritmaların tasarımı, `Makefile` yapılandırması ve performans optimizasyonları.

## Talimatlar (Instructions)
### Derleme
Proje standart C kütüphaneleri ve 42 Norm kurallarına uygun olarak yazılmıştır.
* `make` komutu ile `push_swap` ikili dosyasını derleyebilirsiniz.

### Kullanım (Usage)
Program, sıralanacak tam sayı listesini argüman olarak alır:
`./push_swap 2 1 3 6 5 8`

**Strateji Seçiciler:**
Program varsayılan olarak en uygun algoritmayı seçer, ancak aşağıdaki bayraklarla belirli bir strateji zorlanabilir:
* `--simple`: $O(n^2)$ algoritmasını kullanır.
* `--medium`: $O(n√n)$ algoritmasını kullanır.
* `--complex`: $O(nlogn)$ algoritmasını kullanır.
* `--adaptive`: Düzensizlik oranına göre otomatik seçim yapar (Varsayılan).

**Benchmark Modu:**
`--bench` bayrağı ile operasyon istatistikleri ve düzensizlik oranı `stderr` üzerinden görüntülenebilir:
`./push_swap --bench 4 67 3 87 23`

## Algoritma Seçimleri ve Gerekçeleri
Projede dört ana strateji entegre edilmiştir:

1.  **Basit Algoritma ($O(n^2)$):** Küçük veri setleri için optimize edilmiş, minimum operasyon üreten bir *Insertion Sort* adaptasyonu kullanılmıştır.
2.  **Orta Seviye Algoritma ($O(n√n)$):** Veriyi $√n$ boyutunda aralıklara ayırarak işleyen *Range-based sorting* stratejisi uygulanmıştır.
3.  **Karmaşık Algoritma ($O(nlogn)$):** Büyük veri setlerinde tutarlı performans sağlayan, bit düzeyinde işlem yapan *Radix Sort* (LSD) adaptasyonu tercih edilmiştir.
4.  **Adaptif Seçim Stratejisi:** Program, ilk başta hiçbir hamle yapmadan yığının düzensizlik oranını (0 ile 1 arası) hesaplar. Düzensizlik oranı, hatalı sıralanmış çiftlerin toplam çift sayısına bölünmesiyle bulunur.
    * **Oran < 0.2:** Liste neredeyse sıralı olduğu için $O(n^2)$ algoritmasıyla hızlıca bitirilir.
    * **0.2 <= Oran < 0.5:** Liste orta derecede karışık olduğu için $O(n√n)$ yöntemi uygulanır.
    * **Oran >= 0.5:** Liste yüksek düzensizlikteyse, en güvenli yol olan $O(nlogn)$ devreye girer.

## Kaynaklar (Resources)
* **Donald Knuth:** Algoritmaların matematiksel temelleri ve Big-O notasyonu.
* **42 Curriculum:** Proje isterleri ve Norm standartları.

## Yapay Zeka Kullanımı (AI Usage)
AI araçları, karmaşıklık sınıfları hakkında teknik açıklamalar almak ve farklı ayrıştırma (parsing) mantıkları için prototip oluşturmak amacıyla kullanılmıştır. Üretilen tüm mantık ve kodlar ekip üyeleri tarafından adım adım incelenmiş, hatalar ayıklanmış ve projenin özel bağlamına göre yeniden yazılmıştır.