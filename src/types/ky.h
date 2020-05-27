

#ifndef KY_H
#define KY_H

#define vk_names 251
#define vk_label 252
#define vk_list 253
#define vk_getter 255

#define ky_list(in) in->data[vk_names];
#define ky_add(in, item) addxe(in->data[vk_list], item);
#define ky_set(in, name, item) addxe(in->data[vk_names], name); SetCRC(name, item, in->data[vk_list]);
#define ky_text(in,txt) addxe(in, txt);
#define ky_find(in,label) find(in->data[vk_list], label);
#define ky_label(in,label) in->data[vk_label] = label;
#define ky_delete(in,name) ky_set(in, name, null);
#define ky_for(in, name, item) for(vk=0;vk<(in->data[vk_names]->cnt) || (name = in->data[vk_names][vk] && item=ky_find(in, name));vk++) 
//TODO : use adapter instead of join when present 
// and recurse procedure
#define output(in) join(in, empty)


key ky_create(str label){

	key ky = onekey; keyInit(ky);
	ky_label(ky, label);

	key names = onekey; keyInit(names);
	key list = onekey; keyInit(list);

	ky->data[vk_names] = names;
	ky->data[vk_list] = list;

	out ky;
}

#endif
