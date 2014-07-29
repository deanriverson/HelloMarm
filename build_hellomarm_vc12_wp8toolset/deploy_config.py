# -*- coding: utf-8 -*-
# Deployment settings for HelloMarm.
# This file is autogenerated by the mkb system and used by the s3e deployment
# tool during the build process.

config = {}
cmdline = ['C:/Marmalade/7.3/s3e/makefile_builder/mkb.py', 'c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/HelloMarm.mkb', '--deploy-only', '--hub-data', 'C:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/project_HelloMarm/mkb-wp8.txt', '--buildenv=VC12', '--buildenv-toolset=WP8']
mkb = 'c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/HelloMarm.mkb'
mkf = ['c:\\marmalade\\7.3\\modules\\iwutil\\iwutil.mkf', 'c:\\marmalade\\7.3\\modules\\third_party\\libjpeg\\libjpeg.mkf', 'c:\\marmalade\\7.3\\modules\\third_party\\libpng\\libpng.mkf', 'c:\\marmalade\\7.3\\modules\\third_party\\zlib\\zlib.mkf', 'c:\\marmalade\\7.3\\modules\\iwgx\\iwgx.mkf', 'c:\\marmalade\\7.3\\modules\\iwgl\\iwgl.mkf', 'c:\\marmalade\\7.3\\modules\\iwgeom\\iwgeom.mkf', 'c:\\marmalade\\7.3\\modules\\iwresmanager\\iwresmanager.mkf', 'c:\\marmalade\\7.3\\extensions\\pvrtextool\\pvrtextool.mkf']

class DeployConfig(object):
    pass

######### ASSET GROUPS #############

assets = {}

assets['Default'] = [
    ('c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm\data', '.', 0),
]

######### DEFAULT CONFIG #############

class DefaultConfig(DeployConfig):
    embed_icf = -1
    name = 'HelloMarm'
    pub_sign_key = 0
    priv_sign_key = 0
    caption = 'HelloMarm'
    long_caption = 'HelloMarm'
    version = [0, 0, 1]
    config = ['c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/data/app.icf']
    data_dir = 'c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/data'
    iphone_link_lib = []
    osx_ext_dll = ['c:/marmalade/7.3/extensions/pvrtextool/lib/osx/libPVRTexTool.dylib']
    ws8_ext_capabilities = []
    android_external_res = []
    win32_ext_dll = ['c:/marmalade/7.3/extensions/pvrtextool/lib/win32/PVRTexTool.dll']
    wp8_ext_capabilities = []
    ws81_ext_managed_dll = []
    iphone_link_libdir = []
    android_extra_application_manifest = []
    ws8_ext_native_dll = []
    android_extra_manifest = []
    iphone_link_libdirs = []
    linux_ext_lib = []
    ws8_ext_managed_dll = []
    ws81_ext_sdk_ref_file = []
    ws8_ext_sdk_manifest_part = []
    ws8_ext_device_capabilities = []
    android_external_jars = []
    android_supports_gl_texture = []
    ws81_ext_sdk_manifest_part = []
    ws81_ext_device_capabilities = []
    ws8_ext_sdk_ref = []
    iphone_extra_string = []
    tizen_so = []
    wp8_ext_native_dll = []
    ws81_ext_sdk_ref = []
    iphone_link_opts = []
    ws81_ext_native_dll = []
    wp8_ext_managed_dll = []
    android_so = []
    osx_extra_res = []
    ws81_ext_capabilities = []
    iphone_link_libs = []
    target = {
         'wp8-x86' : {
                   'debug'   : r'c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/build_hellomarm_vc12_wp8toolset/Debug_HelloMarm_VC12_WP8TOOLSET_x86/HelloMarm.s86',
                   'release' : r'c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/build_hellomarm_vc12_wp8toolset/Release_HelloMarm_VC12_WP8TOOLSET_x86/HelloMarm.s86',
                 },
         'wp8-arm' : {
                   'debug'   : r'c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/build_hellomarm_vc12_wp8toolset/Debug_HelloMarm_VC12_WP8TOOLSET_arm/HelloMarm.s86',
                   'release' : r'c:/Users/m1v3rpwn/Documents/GitHub/HelloMarm/build_hellomarm_vc12_wp8toolset/Release_HelloMarm_VC12_WP8TOOLSET_arm/HelloMarm.s86',
                 },
        }
    arm_arch = ''
    assets_original = assets
    assets = assets['Default']

default = DefaultConfig()