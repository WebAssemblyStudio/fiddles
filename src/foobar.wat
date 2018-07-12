(function{camlinternalFormat.ml:27,20-223} camlCamlinternalFormat__add_in_char_set_1061
     (char_set/1062: val c/1063: val)
 (let
   (ind/1064 c/1063 str_ind/1065 (or (>>u ind/1064 3) 1)
    mask/1066 (+ (<< 2 (>>s (and ind/1064 15) 1)) 1))
   (let index/8707799 (>>s str_ind/1065 1)
     (checkbound{camlinternalFormat.ml:30,2-98}
       (let
         tmp/8707802
           (- (<< (>>u (load_mut int (+a char_set/1062 -4)) 10) 2) 1)
         (- tmp/8707802
           (load_mut unsigned int8 (+a char_set/1062 tmp/8707802))))
       index/8707799)
     (store unsigned int8 (+ char_set/1062 index/8707799)
       (>>s
         (app{camlinternalFormat.ml:31,4-69} "camlStdlib__char_of_int_1126"
           (or
             (+
               (<<
                 (let index/8707800 (>>s str_ind/1065 1)
                   (checkbound{camlinternalFormat.ml:31,30-58}
                     (let
                       tmp/8707801
                         (-
                           (<< (>>u (load_mut int (+a char_set/1062 -4)) 10)
                             2)
                           1)
                       (- tmp/8707801
                         (load_mut unsigned int8
                           (+a char_set/1062 tmp/8707801))))
                     index/8707800)
                   (load_mut unsigned int8 (+ char_set/1062 index/8707800)))
                 1)
               1)
             mask/1066)
           val)
         1)))
   1))