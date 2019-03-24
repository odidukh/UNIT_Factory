/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:31:42 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/22 15:26:45 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define AMBIENCE_LIGHT			0.2
# define BCOLOR					0xffffff
# define FOV					90
# define LIGHTSRC_COLOR			0xffffff
# define MOVEMENT_SPEED			0.5
# define PRECISION				1e-6
# define PRERENDER_RES			10
# define REFL_DEPTH				4
# define RENDER_DELAY			2000
# define ROTATION_SPEED			1
# define T_MAX					1000
# define THREAD_AMOUNT			8
# define COLOR_FILTER_AMOUNT	5
# define MAX_OBJ_AMOUNT			100

# define PANEL_W				320
# define PANEL_H				1080
# define VPORT_H				1080
# define VPORT_W				1600
# define WIN_H					1080
# define WIN_W					1920

# define UI_STEP_X				15
# define UI_STEP_Y				32
# define UI_Y					132

# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# if defined(__APPLE__)
#  include <SDL.h>
#  include <SDL_ttf.h>
#  include <SDL_image.h>
# else
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_image.h>
# endif

# include "kiss_sdl.h"
# include "libft.h"

typedef union					u_color
{
	unsigned char				channel[4];
	unsigned int				value;
}								t_color;

typedef enum					e_light_type
{
	TYPE_PLIGHT,
	TYPE_DLIGHT
}								t_light_type;

typedef enum					e_index_name
{
	A,
	B,
	C,
	D,
	X = 0,
	Y,
	Z,
	OX,
	OY,
	OZ,
	SCALE
}								t_index_name;

typedef enum					e_obj_type
{
	TYPE_CONE,
	TYPE_CYL,
	TYPE_LCONE,
	TYPE_LCYL,
	TYPE_PLANE,
	TYPE_SPHERE,
	TYPE_TRIANGLE
}								t_obj_type;

/*
**	Objects structures
*/

typedef struct					s_camera
{
	double						delta[6];
	double						dir[3];
	double						dir_backup[3];
	double						pos[6];
	double						scr_h[3];
	double						scr_h_backup[3];
	double						scr_v[3];
	double						scr_v_backup[3];
}								t_camera;

typedef struct					s_cone
{
	int							index;
	double						angle;
	double						dir[3];
	double						dirc[3];
	double						pos[6];
	double						prm[3];
}								t_cone;

typedef struct					s_cyl
{
	int							index;
	double						dir[3];
	double						dirc[3];
	double						pos[6];
	double						prm[2];
	double						radius;
}								t_cyl;

typedef struct					s_plane
{
	int							index;
	double						dir[3];
	double						dirc[3];
	double						pos[6];
}								t_plane;

typedef struct					s_disk
{
	int							index;
	double						dir[3];
	double						dirc[3];
	double						pos[6];
	double						radius;
}								t_disk;

typedef struct					s_sphere
{
	int							index;
	double						dir[3];
	double						dirc[3];
	double						pos[6];
	double						prm;
	double						radius;
}								t_sphere;

typedef	struct					s_hemisphere
{
	int							index;
	double						dir[3];
	double						dirc[3];
	double						pos[6];
	double						prm;
	double						radius;
}								t_hemisphere;

typedef struct					s_triangle
{
	int							index;
	double						area;
	double						delta[6];
	double						dir[3];
	double						dirc[3];
	double						edge[3][3];
	double						p0[3];
	double						p1[3];
	double						p2[3];
	double						p0_backup[3];
	double						p1_backup[3];
	double						p2_backup[3];
}								t_triangle;

typedef struct					s_lcone
{
	int							index;
	double						dir[3];
	double						dirc[3];
	double						height;
	double						pos[6];
	double						prm[3];
	double						radius;
}								t_lcone;

typedef struct					s_lcyl
{
	int							index;
	double						dir[3];
	double						dirc[3];
	double						pos[6];
	double						prm[2];
	double						radius;
	double						height;
	t_disk						upper_cap;
	t_disk						lower_cap;
}								t_lcyl;

/*
**	Additional structurs for list of light sources and object list
*/

typedef struct					s_ltlst
{
	double						dir[3];
	struct s_ltlst				*next;
	double						pos[6];
	double						power;
	int							type;
}								t_ltlst;

typedef struct					s_objlst
{
	t_obj_type					obj_type;

	int							ui_form_amount;
	kiss_label					title;
	kiss_label					labels[16];
	kiss_entry					entries[16];

	unsigned int				color;
	double						ior;
	double						reflection;
	double						transparency;
	struct s_objlst				*next;
	void						*obj;
	SDL_Surface					*diff_map;
	SDL_Surface					*norm_map;
	double						tmapping[7];

	void						(*apply_live_changes)();
	void						(*apply_changes)();
	void						(*get_uv)();
	void						(*init_values)();
	double						(*is_hit)();
	void						(*set_normvec)();

	void						(*init_ui)();
	void						(*update_values)();
	void						(*update_entries)();
}								t_objlst;

/*
**	Main structure where all window components and functions are stored.
*/

typedef struct					s_info
{
	int							is_changed;
	int							is_prerendered;
	int							is_at_viewport;
	int							selected_filter;
	double						delta[6];
	const Uint8					*keystate;

	kiss_window					viewport;
	kiss_image					canvas;
	SDL_Renderer				*renderer;
	SDL_Surface					*surface;
	t_camera					*cam;
	t_ltlst						*ltlst;
	t_objlst					*objlst;
	t_objlst					**screen_buff;
	t_objlst					*selected;
	kiss_array					*karray;
	void						(*apply_filter[COLOR_FILTER_AMOUNT + 1])();
}								t_info;

/*
**	Main ui structure.
*/

typedef struct					s_ui_panel
{
	int							is_changed;
	int							is_valid_file;

	SDL_Renderer				*renderer;
	kiss_window					panel;

	kiss_array					objects;
	kiss_array					entries;
	kiss_array					textures;
	kiss_array					kiss_objlst;

	kiss_button					btn_filter_prev;
	kiss_button					btn_filter_next;
	kiss_button					btn_filter_reset;

	kiss_label					state_label[2];
	kiss_label					lbl_scene_manager;
	kiss_label					lbl_object_editor;
	kiss_label					lbl_texturing;
	kiss_label					lbl_diff_map;
	kiss_label					lbl_norm_map;

	kiss_label					lbl_filter_title;
	kiss_label					lbl_color_filter[COLOR_FILTER_AMOUNT + 1];
	kiss_label					lbl_tex_delta[2];
	kiss_label					lbl_tex_angle;
	kiss_label					lbl_tex_scale;

	kiss_combobox				cmb_scenes;
	kiss_combobox				cmb_diff_map;
	kiss_combobox				cmb_norm_map;

	SDL_Texture					*dmap_preview;
	SDL_Texture					*nmap_preview;
	SDL_Rect					clip_dmap;
	SDL_Rect					clip_nmap;

	kiss_entry					ent_tex_delta[2];
	kiss_entry					ent_tex_angle;
	kiss_entry					ent_tex_scale;
}								t_ui_panel;

/*
**	Thread managing structure with cached data for rendering
*/

typedef struct					s_cache
{
	int							norm_type[MAX_OBJ_AMOUNT];
	double						unit_vec[3][3];
	t_objlst					*closest;
	int							end_x;
	double						hit[3];
	t_info						*info;
	int							is_prerender;
	double						norm[3];
	double						offset[2];
	double						ray[3];
	int							start_x;
	double						t;
	pthread_t					thread;
}								t_cache;

/*
**	Color tools
*/

unsigned int					add_colors(unsigned int c1,
											unsigned int c2);
void							apply_color_filter(t_info *info,
													int is_prerender);
unsigned int					apply_intensity(unsigned int src_color,
												double intensity);
void							clear_surface(SDL_Surface *surface,
											unsigned int color);
void							draw_point(SDL_Surface *surface,
											int x,
											int y,
											unsigned int color);
void							draw_scaled_point(SDL_Surface *surface,
												int x,
												int y,
												unsigned int color);
void							filter_grayscale(SDL_Surface *surface);
void							filter_sepia(SDL_Surface *surface);
void							filter_negative(SDL_Surface *surface);
void							filter_sketch(SDL_Surface *surface,
												t_objlst **screen_buff);
void							filter_cartoon(SDL_Surface *surface,
												t_objlst **screen_buff);
double							get_diff_intensity(t_cache *cache,
													double cosi);
unsigned int					get_pixel_color(SDL_Surface *surface,
												int x,
												int y);
double							get_spec_intensity(t_cache *cache,
													double cosi);
unsigned int					get_texture_color(SDL_Surface *surface,
												double u,
												double v);
unsigned int					mix_colors(unsigned int c1,
											unsigned int c2,
											double factor);

/*
**	General tools
*/

void							cache_copy(t_cache *dst,
											t_cache *src);
void							clamp_obj_data(t_objlst *selected);
void							clear_info(t_info *info,
											int clear_surface);
void							free_surface(SDL_Surface **surface);
void							free_texture(SDL_Texture **texture);
double							get_min_positive_root(double a,
													double b,
													double c,
													double *roots);
void							ltlst_add(t_ltlst **list,
											t_ltlst *node);
void							ltlst_delete(t_ltlst **list);
t_ltlst							*ltlst_new(int type,
											double *pos,
											double power);
void							objlst_add(t_objlst **list,
											t_objlst *node);
void							objlst_delete(t_objlst **list);
t_objlst						*objlst_new(void *obj);

/*
**	Image tools
*/

void							get_norm_from_map(double *norm,
												unsigned int normvec_info);
SDL_Surface						*load_texture(const char *file,
											SDL_PixelFormat *format);

/*
**	UI tools
*/

void							init_panel(t_ui_panel *panel,
										SDL_Renderer *renderer);
void							init_viewport(t_info *info,
										kiss_array *objects,
										SDL_Renderer *renderer);

/*
**	Event handling
*/

void							dmap_selection_event(t_ui_panel *panel,
													t_info *info,
													SDL_Event *event);
void							handle_keyboard(t_info *info);
void							handle_live_movement(t_info *info);
void							handle_mouse_events(t_info *info,
													SDL_Event *event,
													int *is_at_viewport);
void							handle_panel_events(t_ui_panel *panel,
												t_info *info,
												SDL_Event *event);
void							handle_ui(t_objlst *selected,
										SDL_Event *event,
										int *draw);
void							nmap_selection_event(t_ui_panel *panel,
													t_info *info,
													SDL_Event *event);
void							scene_selection_event(t_ui_panel *panel,
													t_info *info,
													SDL_Event *event);
void							prev_button_event(t_ui_panel *panel,
												t_info *info,
												SDL_Event *e);
void							next_button_event(t_ui_panel *panel,
												t_info *info,
												SDL_Event *e);
void							reset_button_event(t_ui_panel *panel,
												t_info *info,
												SDL_Event *e);

/*
**	Vector tools
*/

void							vecadd(double *v1,
										double *v2,
										double *result,
										size_t size);
void							vecsub(double *v1,
										double *v2,
										double *result,
										size_t size);
void							vecmult(double *v1,
										double coeff,
										double *res,
										size_t size);
void							veccross(double *v1,
										double *v2,
										double *result);
double							vecdot(double *v1,
										double *v2);
double							veclen(double *vec);
void							vecnorm(double *vec);
void							vecrot_ox(double *vec,
										double ox_angle,
										double *point);
void							vecrot_oy(double *vec,
										double oy_angle,
										double *point);
void							vecrot_oz(double *vec,
										double oz_angle,
										double *point);

/*
**	Texturing
*/

void							edit_mapping(double *tmap,
											double *raw_point);
void							get_cone_uv(t_cache *cache,
											double *u,
											double *v);
void							get_cyl_uv(t_cache *cache,
											double *u,
											double *v);
void							get_hemisphere_uv(t_cache *cache,
												double *u,
												double *v);
void							get_lcone_uv(t_cache *cache,
											double *u,
											double *v);
void							get_lcyl_uv(t_cache *cache,
												double *u,
												double *v);
void							get_plane_uv(t_cache *cache,
											double *u,
											double *v);
void							get_sphere_uv(t_cache *cache,
											double *u,
											double *v);
void							get_triangle_uv(t_cache *cache,
												double *u,
												double *v);

/*
**	Rendering
*/

double							get_fresnel_val(t_cache *cache,
												double cosi);
void							handle_ray_deflection(t_cache *cache,
													double cosi,
													unsigned int *color,
													int depth);
void							*render_part(void *arg);
void							render_scene(t_info *info,
											int is_prerender);
unsigned int					trace_ray(t_cache *data,
										double *start,
										unsigned int depth,
										int *is_hit);
unsigned int					trace_reflected(t_cache *cache,
												double cosi,
												unsigned int depth);
unsigned int					trace_refracted(t_cache *cache,
												double cosi,
												unsigned int depth);

/*
**	Objects
*/

t_camera						*create_camera(double *pos);
t_cone							*create_cone(double *pos,
											double angle);
t_cyl							*create_cyl(double *pos,
											double radius);
t_disk							*create_disk(double *pos,
											double radius);
t_hemisphere					*create_hemisphere(double *pos,
												double radius);
t_lcone							*create_lcone(double *pos,
											double radius,
											double height);
t_lcyl							*create_lcyl(double *pos,
											double radius,
											double height);
t_plane							*create_plane(double *pos);
t_sphere						*create_sphere(double *pos,
												double radius);
t_triangle						*create_triangle(double *p0,
												double *p1,
												double *p2);
void							define_cone_constants(void *obj,
													double *viewpos);
void							define_cyl_constants(void *obj,
													double *viewpos);
void							define_hemisphere_constants(void *obj,
														double *viewpos);
void							define_lcone_constants(void *obj,
														double *viewpos);
void							define_lcyl_constants(void *obj,
														double *viewpos);
void							define_plane_constants(void *obj,
														double *viewpos);
void							define_sphere_constants(void *obj,
														double *viewpos);
void							define_triangle_constants(void *obj,
														double *viewpos);
void							edit_camera_live(t_camera *cam,
												double *cam_delta);
void							edit_cone_live(t_objlst *this,
												double *delta);
void							edit_cyl_live(t_objlst *this,
												double *delta);
void							edit_hemisphere_live(t_objlst *this,
													double *delta);
void							edit_lcone_live(t_objlst *this,
												double *delta);
void							edit_lcyl_live(t_objlst *this,
												double *delta);
void							edit_plane_live(t_objlst *this,
												double *delta);
void							edit_sphere_live(t_objlst *this,
												double *delta);
void							edit_triangle_live(t_objlst *this,
													double *delta);
void							edit_cone(t_objlst *this);
void							edit_cyl(t_objlst *this);
void							edit_disk(t_objlst *this);
void							edit_hemisphere(t_objlst *this);
void							edit_lcone(t_objlst *this);
void							edit_lcyl(t_objlst *this);
void							edit_plane(t_objlst *this);
void							edit_sphere(t_objlst *this);
void							edit_triangle(t_objlst *this);
double							hit_cone(void *obj,
										double *ray,
										double *start,
										t_cache *cache);
double							hit_cyl(void *obj,
										double *ray,
										double *start,
										t_cache *cache);
double							hit_disk(void *obj,
										double *ray,
										double *start,
										t_cache *cache);
double							hit_hemisphere(void *obj,
											double *ray,
											double *start,
											t_cache *cache);
double							hit_lcone(void *obj,
										double *ray,
										double *start,
										t_cache *cache);
double							hit_lcyl(void *obj,
											double *ray,
											double *start,
											t_cache *cache);
double							choose_caps(t_lcyl *tmp,
											t_cache *cache,
											double d[],
											double t[]);
double							hit_plane(void *obj,
										double *ray,
										double *start,
										t_cache *cache);
double							hit_sphere(void *obj,
										double *ray,
										double *start,
										t_cache *cache);
double							hit_triangle(void *obj,
											double *ray,
											double *start,
											t_cache *cache);
void							set_cone_normvec(t_cache *cache);
void							set_lcone_normvec(t_cache *cache);
void							set_cyl_normvec(t_cache *cache);
void							set_lcyl_normvec(t_cache *cache);
void							set_obj_constants(t_info *info,
												double *start);
void							set_plane_normvec(t_cache *cache);
void							set_sphere_normvec(t_cache *cache);
void							set_triangle_normvec(t_cache *cache);
void							set_hemisphere_normvec(t_cache *cache);

/*
**	UI stuff
*/

void							draw_ui(SDL_Renderer *renderer,
										t_objlst *selected);
void							init_plane_ui(t_ui_panel *panel,
											t_objlst *selected);
void							init_disk_ui(t_ui_panel *panel,
											t_objlst *selected);
void							init_hemisphere_ui(t_ui_panel *panel,
												t_objlst *selected);
void							init_sphere_ui(t_ui_panel *panel,
											t_objlst *selected);
void							init_cone_ui(t_ui_panel *panel,
											t_objlst *selected);
void							init_lcone_ui(t_ui_panel *panel,
											t_objlst *selected);
void							init_cyl_ui(t_ui_panel *panel,
											t_objlst *selected);
void							init_lcyl_ui(t_ui_panel *panel,
											t_objlst *selected);
void							init_triangle_ui(t_ui_panel *panel,
											t_objlst *selected);
void							kiss_update_surface(SDL_Surface *surface,
													kiss_image *image,
													kiss_array *a,
													SDL_Renderer *renderer);
void							update_all(t_ui_panel *panel,
											t_info *info);
void							update_dirent(char *dir,
											kiss_array *entries,
											char *ftype);
void							update_plane_values(t_objlst *selected);
void							update_disk_values(t_objlst *selected);
void							update_hemisphere_values(t_objlst *selected);
void							update_sphere_values(t_objlst *selected);
void							update_cone_values(t_objlst *selected);
void							update_cyl_values(t_objlst *selected);
void							update_lcone_values(t_objlst *selected);
void							update_lcyl_values(t_objlst *selected);
void							update_triangle_values(t_objlst *selected);
void							update_plane_entries(t_objlst *selected);
void							update_disk_entries(t_objlst *selected);
void							update_hemisphere_entries(t_objlst *selected);
void							update_sphere_entries(t_objlst *selected);
void							update_cone_entries(t_objlst *selected);
void							update_cyl_entries(t_objlst *selected);
void							update_lcone_entries(t_objlst *selected);
void							update_lcyl_entries(t_objlst *selected);
void							update_triangle_entries(t_objlst *selected);

/*
**	Parser stuff
*/

t_ltlst							*get_lights(void);
char							*get_whole_file_text(char *file);
char							*cone_parser(char *text,
											char *formated_str);
char							*cylinder_parser(char *text,
												char *formated_str);
char							*disk_parser(char *text,
											char *formated_str);
char							*hemisphere_parser(char *text,
												char *formated_str);
char							*limit_cone_parser(char *text,
												char *formated_str);
char							*limit_cylinder_parser(char *text,
													char *formated_str);
char							*plane_parser(char *text,
											char *formated_str);
char							*sphere_parser(char *text,
											char *formated_str);
char							*triangle_parser(char *text,
												char *formated_str);
char							*camera_parser(char *text,
												char *formated_str);
char							*light_direct_parser(char *text,
													char *formated_str);
char							*light_point_parser(char *text,
													char *formated_str);
char							*get_formated_string(char *text);
char							*get_whole_file_text(char *file);
int								check_file_text(char *text);
char							*position(char *text,
										char *formated_str);
char							*rotation(char *text,
										char *formated_str);
char							*intensivity(char *text,
											char *formated_str);
char							*angle(char *text,
										char *formated_str);
char							*radius(char *text,
										char *formated_str);
char							*height(char *text,
										char *formated_str);
char							*reflection(char *text,
											char *formated_str);
char							*transparency(char *text,
											char *formated_str);
char							*ior(char *text,
									char *formated_str);
char							*color(char *text,
										char *formated_str);
char							*point_1(char *text,
										char *res_srt);
char							*point_2(char *text,
										char *res_srt);
char							*point_3(char *text,
										char *res_srt);
char							*split_2_with_coma(char *line,
													char *formated_str);
void							single_value_parse(char **line,
													char *formated_str,
													char *word,
													int *check);
t_objlst						*cone_sscanf(char *line,
											t_objlst *node,
											t_cone *tmp);
t_objlst						*lcone_sscanf(char *line,
											t_objlst *node,
											t_lcone *tmp);
t_objlst						*cyl_sscanf(char *line,
											t_objlst *node,
											t_cyl *tmp);
t_objlst						*lim_cyl_sscanf(char *line,
												t_objlst *node,
												t_lcyl *tmp);
t_objlst						*plane_sscanf(char *line,
											t_objlst *node,
											t_plane *tmp);
t_objlst						*disk_sscanf(char *line,
											t_objlst *node,
											t_disk *tmp);
t_objlst						*hemisphere_sscanf(char *line,
												t_objlst *node,
												t_hemisphere *tmp);
t_objlst						*sphere_sscanf(char *line,
											t_objlst *node,
											t_sphere *tmp);
t_objlst						*triangle_sscanf(char *line,
											t_objlst *node,
											t_triangle *tmp);
int								parse_file(char *file,
											t_info *info);
void							parse_cam(char *line,
											t_camera **cam);
void							parse_point_light(char *line,
											t_ltlst **ltlst);
void							parse_volume_light(char *line,
													t_ltlst **list);
void							parse_direct_light(char *line,
											t_ltlst **ltlst);
void							parse_lcone(char *line,
											t_objlst **objlst);
void							parse_cone(char *line,
											t_objlst **objlst);
void							parse_cyl(char *line,
											t_objlst **objlst);
void							parse_lim_cyl(char *line,
											t_objlst **objlst);
void							parse_plane(char *line,
											t_objlst **objlst);
void							parse_sphere(char *line,
											t_objlst **objlst);
void							parse_triangle(char *line,
											t_objlst **objlst);
void							parse_disk(char *line,
											t_objlst **objlst);
void							parse_hemisphere(char *line,
											t_objlst **objlst);

#endif
