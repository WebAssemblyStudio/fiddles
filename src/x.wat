(function{list.ml:285,15-657} camlStdlib__list__sort_1320
     (n/1322: val l/1323: val env/102170: val)
 (catch
   (if (!= n/1322 5)
     (if (!= n/1322 7) (exit 14)
       (if (!= l/1323 1)
         (let *match*/102004 (load_mut val (+a l/1323 4))
           (if (!= *match*/102004 1)
             (let *match*/102005 (load_mut val (+a *match*/102004 4))
               (if (!= *match*/102005 1)
                 (let
                   (x3/1328 (load_mut val *match*/102005)
                    x2/1327 (load_mut val *match*/102004)
                    x1/1326 (load_mut val l/1323))
                   (if
                     (<=
                       (app{list.ml:290,10-19} "caml_apply2" x1/1326 x2/1327
                         (load val (+a env/102170 28)) val)
                       1)
                     (if
                       (<=
                         (app{list.ml:291,12-21} "caml_apply2" x2/1327
                           x3/1328 (load val (+a env/102170 28)) val)
                         1)
                       (alloc{list.ml:291,32-44}
                         block-hdr(2048){list.ml:291,32-44} x1/1326
                         (alloc{list.ml:291,37-44}
                           block-hdr(2048){list.ml:291,37-44} x2/1327
                           (alloc{list.ml:291,41-44}
                             block-hdr(2048){list.ml:291,41-44} x3/1328 1)))
                       (if
                         (<=
                           (app{list.ml:292,17-26} "caml_apply2" x1/1326
                             x3/1328 (load val (+a env/102170 28)) val)
                           1)
                         (alloc{list.ml:292,37-49}
                           block-hdr(2048){list.ml:292,37-49} x1/1326
                           (alloc{list.ml:292,42-49}
                             block-hdr(2048){list.ml:292,42-49} x3/1328
                             (alloc{list.ml:292,46-49}
                               block-hdr(2048){list.ml:292,46-49} x2/1327 1)))
                         (alloc{list.ml:293,14-26}
                           block-hdr(2048){list.ml:293,14-26} x3/1328
                           (alloc{list.ml:293,19-26}
                             block-hdr(2048){list.ml:293,19-26} x1/1326
                             (alloc{list.ml:293,23-26}
                               block-hdr(2048){list.ml:293,23-26} x2/1327 1)))))
                     (if
                       (<=
                         (app{list.ml:295,12-21} "caml_apply2" x1/1326
                           x3/1328 (load val (+a env/102170 28)) val)
                         1)
                       (alloc{list.ml:295,32-44}
                         block-hdr(2048){list.ml:295,32-44} x2/1327
                         (alloc{list.ml:295,37-44}
                           block-hdr(2048){list.ml:295,37-44} x1/1326
                           (alloc{list.ml:295,41-44}
                             block-hdr(2048){list.ml:295,41-44} x3/1328 1)))
                       (if
                         (<=
                           (app{list.ml:296,17-26} "caml_apply2" x2/1327
                             x3/1328 (load val (+a env/102170 28)) val)
                           1)
                         (alloc{list.ml:296,37-49}
                           block-hdr(2048){list.ml:296,37-49} x2/1327
                           (alloc{list.ml:296,42-49}
                             block-hdr(2048){list.ml:296,42-49} x3/1328
                             (alloc{list.ml:296,46-49}
                               block-hdr(2048){list.ml:296,46-49} x1/1326 1)))
                         (alloc{list.ml:297,14-26}
                           block-hdr(2048){list.ml:297,14-26} x3/1328
                           (alloc{list.ml:297,19-26}
                             block-hdr(2048){list.ml:297,19-26} x2/1327
                             (alloc{list.ml:297,23-26}
                               block-hdr(2048){list.ml:297,23-26} x1/1326 1)))))))
                 (exit 14)))
             (exit 14)))
         (exit 14)))
     (if (!= l/1323 1)
       (let *match*/102002 (load_mut val (+a l/1323 4))
         (if (!= *match*/102002 1)
           (let
             (x2/1325 (load_mut val *match*/102002)
              x1/1324 (load_mut val l/1323))
             (if
               (<=
                 (app{list.ml:288,10-19} "caml_apply2" x1/1324 x2/1325
                   (load val (+a env/102170 28)) val)
                 1)
               (alloc{list.ml:288,30-38} block-hdr(2048){list.ml:288,30-38}
                 x1/1324
                 (alloc{list.ml:288,35-38} block-hdr(2048){list.ml:288,35-38}
                   x2/1325 1))
               (alloc{list.ml:288,44-52} block-hdr(2048){list.ml:288,44-52}
                 x2/1325
                 (alloc{list.ml:288,49-52} block-hdr(2048){list.ml:288,49-52}
                   x1/1324 1))))
           (exit 14)))
       (exit 14)))
 with(14)
   (let
     (n1/1331 (or (>>s n/1322 1) 1) n2/1332 (+ (- n/1322 n1/1331) 1)
      l2/1333
        (app{list.ml:302,16-25} "camlStdlib__list__chop_1293" n1/1331 l/1323
          val)
      s1/1334
        (app{list.ml:303,16-29} "camlStdlib__list__rev_sort_1321" n1/1331
          l/1323 (+v env/102170 16) val)
      s2/1335
        (app{list.ml:304,16-30} "camlStdlib__list__rev_sort_1321" n2/1332
          l2/1333 (+v env/102170 16) val))
     (app{list.ml:305,7-29} "camlStdlib__list__rev_merge_rev_1310" s1/1334
       s2/1335 1 (load val (+a env/102170 36)) val))))