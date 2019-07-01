// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.

enum ShiftAlong {
	Width,
	Height
}
// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.

/*
(
"s", 
600,
450,
180,
214,
0.337,
0.448,
99.663,
99.552,
24.731,
67.469,
67.469,
33.978,
64.165,
20.034,
63.789,
26.25,
62.667,
"2",
1)
*/

#[wasm_bindgen]
pub fn prepareCropByRust (  
    aspect_ratio_kind:  &str,
    Image_width:        f64,
    Image_height:       f64,
    ratio_width:        f64,
    ratio_height:       f64,
    Crop_left:          f64, 
    Crop_top:           f64, 
    Crop_width:         f64, 
    Crop_height:        f64, 
    Main_focus_centerx: f64, 
    Main_focus_centery: f64,
    Main_focus_width:   f64,
    Main_focus_height:  f64, 
    Sub_focus_x:        f64, 
    Sub_focus_y:        f64,
    x_axis:             f64,
    y_axis:             f64,
    rotate:			    &str,
    crop_mode:          u8) -> String {

      	let mut main_focus_centerx = Main_focus_centerx * Image_width  / 100.0;
        let mut main_focus_centery = Main_focus_centery * Image_height / 100.0;
        let mut main_focus_width   = Main_focus_width   * Image_width  / 100.0;
        let mut main_focus_height  = Main_focus_height  * Image_height / 100.0;
        
        let mut sub_focus_x = Sub_focus_x * Image_width  / 100.0;
        let mut sub_focus_y = Sub_focus_y * Image_height / 100.0;
        
        let mut crop_width  = Crop_width  * Image_width  / 100.0;
        let mut crop_height = Crop_height * Image_height / 100.0;
        let mut crop_left   = Crop_left   * Image_width  / 100.0;
        let mut crop_top    = Crop_top    * Image_height / 100.0;

        let mut my_shift_along;

        let mut my_crop_top  = crop_top;
        let mut my_crop_left = crop_left;

        let mut my_outer_width;
        let mut my_outer_height;

        let mut main_focusx      = (main_focus_centerx - (main_focus_width / 2.0)) - crop_left ;
        let mut main_focus_right = main_focusx + main_focus_width;

        let mut main_focusy       = (main_focus_centery - (main_focus_height / 2.0)) - crop_top ;
	    let mut main_focus_bottom = main_focusy + main_focus_height;

		if crop_mode == 2 {
		  // take inner (green Frame)
		  my_outer_width  = main_focus_width;
		  my_outer_height = main_focus_height;
		  my_crop_left    = main_focusx;
		  my_crop_top     = main_focusy;
		} else {
		  // take outer (red Frame) Width etc
		  my_outer_width  = crop_width;
		  my_outer_height = crop_height;
		}

				let mut  my_ratio_width;
    	let mut  my_ratio_height;
    
    	/* swap ratio if image is rotated */
   		if ( (rotate == "5") || (rotate == "6") ||(rotate == "7") ||(rotate == "8")) {
    		my_ratio_width  = ratio_height;
    		my_ratio_height = ratio_width;
		} else {
    		my_ratio_width  = ratio_width;
    		my_ratio_height = ratio_height;
		}

		let target_aspect_ratio  : f64 = my_ratio_width / my_ratio_height;
		let mut crop_pane_width;
		let mut crop_pane_height;
	  
		if target_aspect_ratio >= 1.0 {

			crop_pane_width  = my_outer_width;
			crop_pane_height = my_outer_width / target_aspect_ratio;
			my_shift_along   = ShiftAlong::Height;

			if crop_pane_height > my_outer_height {
				crop_pane_height  = my_outer_height;
				crop_pane_width   = my_outer_height * target_aspect_ratio;
				my_shift_along    = ShiftAlong::Width;
			}

		} else {

			crop_pane_height = my_outer_height;
			crop_pane_width  = my_outer_height * target_aspect_ratio;
			my_shift_along   = ShiftAlong::Width;

			if crop_pane_width  > my_outer_width  {
				crop_pane_width  = my_outer_width;
				crop_pane_height = my_outer_width / target_aspect_ratio;
				my_shift_along   = ShiftAlong::Height;
			}

		}

        let mut left_box_border       : f64 = 0.0;
		let mut top_box_border    : f64 = 0.0;
		let mut right_box_border  : f64 = 0.0;
		let mut bottom_box_border : f64 = 0.0;
		let mut test_main_focusx  : f64 = 0.0;
		let mut test_main_focusy  : f64 = 0.0;

      
		match my_shift_along {
			// width here
			ShiftAlong::Width => {
				if crop_mode == 2 {					
					if (target_aspect_ratio < 0.23) && (x_axis != 0.0) {
						left_box_border = (x_axis * my_outer_width / 100.0) - (crop_pane_width / 2.0);
					} else {
						let sub_focusx1 : f64 = sub_focus_x - main_focusx;					
						left_box_border = sub_focusx1 - (crop_pane_width * sub_focusx1 / my_outer_width);
					}
					right_box_border  = left_box_border + crop_pane_width;
					bottom_box_border = top_box_border + main_focus_height ;
					test_main_focusx  = 0.0;
				} else {	
					if (target_aspect_ratio < 0.23) && (x_axis != 0.0) {	
						left_box_border = (x_axis * my_outer_width / 100.0) - (crop_pane_width / 2.0);
					} else {
						left_box_border   = sub_focus_x - (crop_pane_width * sub_focus_x / my_outer_width);
					}

					right_box_border  = left_box_border + crop_pane_width;
					bottom_box_border = top_box_border + crop_height ;		
					test_main_focusx  = main_focusx;
				}
			  	// the box is smaller then red frame?
			  if crop_pane_width < main_focus_width {
				// We have to take care not to position outside
				  if left_box_border < test_main_focusx {
					  left_box_border = test_main_focusx;
					  // right_box_border = left_box_border +crop_pane_width; 
				  } else if right_box_border > main_focus_right {
					  right_box_border = main_focus_right;
					  left_box_border = right_box_border - crop_pane_width;
				  }
			  } else {
			      // the box is wider than the red Frame
			      // We have to take care not to leave the workpane
			  	  if left_box_border > test_main_focusx {
					  left_box_border = test_main_focusx;
					  // right_box_border = left_box_border + crop_pane_width;
				  } else if right_box_border < main_focus_right {
					  right_box_border = main_focus_right;
					  left_box_border = right_box_border - crop_pane_width;
				  }
			  }
			},
			// anything else
			_ => {
			if crop_mode == 2 {
				if (target_aspect_ratio < 6.174) && (y_axis != 0.0) {	
					top_box_border  = (y_axis * my_outer_height / 100.0) - (crop_pane_height / 2.0);
				} else {
					let sub_focusy1 : f64 = sub_focus_y - main_focusy;
					top_box_border  = sub_focusy1 - (crop_pane_height * sub_focusy1 / my_outer_height);
				}
				bottom_box_border = top_box_border + crop_pane_height;
				right_box_border  = left_box_border + main_focus_width ;
				test_main_focusy  = 0.0;
			} else {
				if (target_aspect_ratio < 6.174) && (y_axis != 0.0) {
					top_box_border  = (y_axis * my_outer_height / 100.0) - (crop_pane_height / 2.0);
				} else {
					top_box_border    = sub_focus_y - (crop_pane_height * sub_focus_y / my_outer_height);
				}


				bottom_box_border = top_box_border + crop_pane_height;
				right_box_border  = left_box_border + crop_width ;
				test_main_focusy  = main_focusy;
			}
			// the box higher then red frame?
			  if crop_pane_height < main_focus_height {
				// We have to take care not to position outside
				  if top_box_border < test_main_focusy  {
					  top_box_border = test_main_focusy;
					  bottom_box_border = top_box_border + crop_pane_height;
				  } else if bottom_box_border > main_focus_bottom {
					  bottom_box_border = main_focus_bottom;
					  top_box_border = bottom_box_border - crop_pane_height;
				  }
			  } else {
				  if top_box_border > test_main_focusy {
					  top_box_border = test_main_focusy;
					  bottom_box_border = top_box_border + crop_pane_height;
				  } else if bottom_box_border < main_focus_bottom {
					  bottom_box_border = main_focus_bottom;
					  top_box_border = bottom_box_border - crop_pane_height;
				  }
			  }
			}
		}

		let mut my_resize  = format!("{}","");

		if aspect_ratio_kind == "s" {
			my_resize  = format!("{}:{}", my_ratio_width.round(), my_ratio_height.round()); 
		}

	  format!("{}:{}:{}:{}:{}:{}:{}:{}:{}:",
			my_outer_width.round(),
			my_outer_height.round(),
			my_crop_left.round(),
			my_crop_top.round(),
			crop_pane_width.round(),
			crop_pane_height.round(),
			left_box_border.round(),
			top_box_border.round(),
			my_resize
      )
    // let return_string = format!("Hello {} {}", aspect_ratio_kind, ratio_width);

    //alert( &return_string);
    // alert(&format!("Hello, {}!", name));
}

