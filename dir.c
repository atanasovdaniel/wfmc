#include "wfm.h"

//char ICO_FAV[256];
char ICO_DIR[256], ICO_AUP[256], ICO_ADN[256], ICO_GEN[256], ICO_NEW[256], ICO_ZIP[256];
char ICO_IMG[256], ICO_OFF[256], ICO_PDF[256];
char ICO_TXT[256], ICO_EXE[256], ICO_MED[257], ICO_ISO[256], ICO_LNK[256], ICO_DSK[256], ICO_EDT[256];
regex_t reg_zip, reg_img, reg_pdf, reg_exe, reg_txt, reg_off, reg_med, reg_iso, reg_lnk;

char M_HR[]="<FONT COLOR=\"#000000\" STYLE=\"font-weight:bold;\">(Last Hour)";
char M_DAY[]="<FONT COLOR=\"#505050\" STYLE=\"font-weight:bold;\">(Last Day)";
char M_WK[]="<FONT COLOR=\"#000000\">(Last Week)";
//char M_2WK[]="<FONT COLOR=\"#000000\">(Last 2 Weeks)";
char M_MO[]="<FONT COLOR=\"#505050\">(Last Month)";
//char M_2MO[]="<FONT COLOR=\"#505050\">(Last 2 Months)";
//char M_6MO[]="<FONT COLOR=\"#707070\">(Last 6 Months)";
char M_YR[]="<FONT COLOR=\"#909090\">(Last Year)";
char M_OLD[]="<FONT COLOR=\"#C0C0C0\">(Old)";

char tNORMAL_COLOR[]="FFFFFF";
char tALTER_COLOR[]="F0F0F0"; // for alternating lines
char tHIGH_COLOR[]="33CC33";
char tHL_COLOR[]="FFD700";

static const char *access_string[]={ "none", "readonly", "readwrite" };

void dir_icoinita(void) {
    //snprintf(ICO_FAV, sizeof(ICO_FAV), "<IMG SRC=\"%s%s\" ALT=\"Favicon\" ALIGN=\"MIDDLE\" BORDER=\"0\">", rt.iconsurl, rt.favicon);
    snprintf(ICO_DIR, sizeof(ICO_DIR), "<IMG SRC=\"%sdir.gif\" ALT=\"Dir\" ALIGN=\"MIDDLE\" BORDER=\"0\">", rt.iconsurl);
    snprintf(ICO_LNK, sizeof(ICO_LNK), "<IMG SRC=\"%sext.gif\" ALT=\"Link/Shortcut\" ALIGN=\"MIDDLE\" BORDER=\"0\">", rt.iconsurl);
    snprintf(ICO_AUP, sizeof(ICO_AUP), "<IMG SRC=\"%saup.gif\" ALT=\"Up\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"7\" HEIGHT=\"4\">", rt.iconsurl);
    snprintf(ICO_ADN, sizeof(ICO_ADN), "<IMG SRC=\"%sadn.gif\" ALT=\"Down\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"7\" HEIGHT=\"4\">", rt.iconsurl);
    snprintf(ICO_GEN, sizeof(ICO_GEN), "<IMG SRC=\"%sgen.gif\" ALT=\"Unknown\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_NEW, sizeof(ICO_NEW), "<IMG SRC=\"%sarr.gif\" ALT=\"New\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_ZIP, sizeof(ICO_ZIP), "<IMG SRC=\"%szip.gif\" ALT=\"Archive\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_IMG, sizeof(ICO_IMG), "<IMG SRC=\"%simg.gif\" ALT=\"Image\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_OFF, sizeof(ICO_OFF), "<IMG SRC=\"%soff.gif\" ALT=\"Office File\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_PDF, sizeof(ICO_PDF), "<IMG SRC=\"%spdf.gif\" ALT=\"PDF\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_TXT, sizeof(ICO_TXT), "<IMG SRC=\"%stxt.gif\" ALT=\"Text\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_EXE, sizeof(ICO_EXE), "<IMG SRC=\"%sexe.gif\" ALT=\"Exec\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_MED, sizeof(ICO_MED), "<IMG SRC=\"%smed.gif\" ALT=\"Multimedia\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_ISO, sizeof(ICO_ISO), "<IMG SRC=\"%siso.gif\" ALT=\"Disk Image\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_DSK, sizeof(ICO_DSK), "<IMG SRC=\"%sdisk.gif\" ALT=\"Save\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);
    snprintf(ICO_EDT, sizeof(ICO_EDT), "<IMG SRC=\"%sedit.gif\" ALT=\"Edit\" ALIGN=\"MIDDLE\" BORDER=\"0\" WIDTH=\"16\" HEIGHT=\"16\">", rt.iconsurl);

    if(
        regcomp(&reg_zip, "\\.(zip|rar|tar|gz|tgz|z|arj|bz|tbz|7z|xz)$",            REG_EXTENDED | REG_ICASE)!=0 ||
        regcomp(&reg_img, "\\.(gif|png|tif|tiff|jpg|jpeg)$",                        REG_EXTENDED | REG_ICASE)!=0 ||
        regcomp(&reg_off, "\\.(doc|docx|rtf|dot|xls|xlsx|ppt|pptx|off)$",           REG_EXTENDED | REG_ICASE)!=0 ||
        regcomp(&reg_iso, "\\.(iso|flp|img|nrg|dmg)$",                              REG_EXTENDED | REG_ICASE)!=0 ||
        regcomp(&reg_med, "\\.(mp3|mp4|vaw|mov|avi|ivr|mkv)$",                      REG_EXTENDED | REG_ICASE)!=0 ||
        regcomp(&reg_pdf, "\\.(pdf|ps|eps|ai)$",                                    REG_EXTENDED | REG_ICASE)!=0 ||
        regcomp(&reg_exe, "\\.(exe|com|pif)$",                                      REG_EXTENDED | REG_ICASE)!=0 ||
        regcomp(&reg_lnk, "\\.(url|lnk|desktop|shortcut|webloc)$",                  REG_EXTENDED | REG_ICASE)!=0 ||
        regcomp(&reg_txt, "\\.(txt|asc|nfo|me|md|log|htm|html|shtml|js|jsp|php|xml|dtd|css|bas|c|h|cpp|cmd|bat|sh|ksh|awk|reg|bak|cfg|conf|py|json|yaml)$", REG_EXTENDED | REG_ICASE)!=0
    ) error("Unable to compile regex.");

}


//
// Display directory list main panel
//
void dirlist(void) {
    ASDIR *direntry;
    off_t size, totalsize=0;
    char highlight[sizeof(wp.virt_filename)]={0};
    char namepfx[1024], sizepfx[1024], datepfx[1024];
    char rtime[64], mtime[64], atime[64];
#ifndef WFMSIMPLETIME
    char *stime;
#endif
    char sortby[64]={0};
    char *name, *name_urlencoded, *icon, *linecolor, *action, *raction, *ricon, *laction, *licon;
    int nentr=0, e=0, n=1;
    int editable, is_link;
    int upload_id=0;
    time_t now;

    time(&now);
//    upload_id=ftok(getenv("SCRIPT_FILENAME"), getpid());
//    if(upload_id<1)
//        upload_id=now; // holy shit

    cgiFormStringNoNewlines("highlight", highlight, sizeof(wp.virt_filename)-1); //TODO: urlencode ?
    cgiFormStringNoNewlines("sortby", sortby, 63);
    if(strlen(sortby)<4)
        snprintf(sortby, 63, "name");

    //
    // Get and Print Directory Entries
    //
         if(strcmp(sortby, "name")==0)        nentr=asscandir(wp.phys_dirname, &direntry, namesort);
    else if(strcmp(sortby, "rname")==0)       nentr=asscandir(wp.phys_dirname, &direntry, rnamesort);
    else if(strcmp(sortby, "size")==0)        nentr=asscandir(wp.phys_dirname, &direntry, sizesort);
    else if(strcmp(sortby, "rsize")==0)       nentr=asscandir(wp.phys_dirname, &direntry, rsizesort);
    else if(strcmp(sortby, "date")==0)        nentr=asscandir(wp.phys_dirname, &direntry, timesort);
    else if(strcmp(sortby, "rdate")==0)       nentr=asscandir(wp.phys_dirname, &direntry, rtimesort);
    else                                      nentr=asscandir(wp.phys_dirname, &direntry, namesort);

    dir_icoinita();

    cgiHeaderContentType("text/html");

    //
    // HTML HEADER
    //
    fprintf(cgiOut,
        "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"\n\"http://www.w3.org/TR/html4/loose.dtd\">\n"
        "\n%s\n"
        "<HTML LANG=\"en\">\n"
        "<HEAD>\n"
        "<TITLE>%s : %c%s</TITLE>\n",
        COPYRIGHT, cfg.tagline, (strlen(wp.virt_dirname)>0) ? ' ' : '/', wp.virt_dirname);

    if(rt.js) fprintf(cgiOut,
        "<SCRIPT LANGUAGE=\"JavaScript\" TYPE=\"text/javascript\">\n"
        "<!-- \n"
        "function checkUncheckAll(checkAllState, cbGroup) {\n"
        "    if(cbGroup.length > 0) {\n"
        "        for (i = 0; i < cbGroup.length; i++) {\n"
        "            cbGroup[i].checked = checkAllState.checked;\n"
        "        }\n"
        "    }\n"
        "    else {\n"
        "        cbGroup.checked = checkAllState.checked;\n"
        "    }\n"
        "}\n");

/*    this code is for fancy upload status via ajax call to cgic counterpart
        if(rt.js>=2) fprintf(cgiOut,
        "function xmlhttpPost(strURL) {\n"
        "    var xmlHttpReq = false;\n"
        "    var self = this;\n"
        "    var method = \"GET\";\n"
        "    \n"
        "   if (window.XMLHttpRequest) {\n"
        "      self.xmlHttpReq = new XMLHttpRequest();\n"
        "   }\n"
        "   else if (window.ActiveXObject) {\n"
        "      self.xmlHttpReq = new ActiveXObject(\"Microsoft.XMLHTTP\");\n"
        "}\n"
        "if (self.xmlHttpReq != null) {\n"
        "      self.xmlHttpReq.open(method, strURL, true);\n"
        "      self.xmlHttpReq.onreadystatechange = function () {\n"
        "         if (self.xmlHttpReq.readyState == 4) {\n"
        "            var result = document.getElementById(\"Upload_Status\");\n"
        "            result.value = self.xmlHttpReq.responseText;\n"
        "         }\n"
        "      }\n"
        "        self.xmlHttpReq.send(null);\n"
        "   }\n"
        "}\n"
        "\n"
        "function start() {\n"
        "   setInterval('xmlhttpPost(\"%s?ea=upstat&upload_id=%d\");', 250);\n"
        "}\n",
        cgiScriptName, upload_id);*/

    if(rt.js) fprintf(cgiOut,
        "//-->\n"
        "</SCRIPT>\n");


    fprintf(cgiOut,
        "<STYLE TYPE=\"text/css\">\n"
        "<!--\n"
        "A:link {text-decoration: none; color:#0000CE; } \n"
        "A:visited {text-decoration: none; color:#0000CE; } \n"
        "A:active {text-decoration: none; color:#FF0000; } \n"
        "A:hover {text-decoration: none; color:#FF0000; } \n"
        "html, body, table { width:100%%; margin:0px; padding:0px; border:none; } \n"
        "img { vertical-align:middle; } \n"
        "td, th { font-family: Tahoma, Arial, Geneva, sans-serif; font-size:%s; margin:0px; padding:2px; border:none;  } \n"
        "input { border-color:#000000;border-style:solid; \n"
        "font-family: Tahoma, Arial, Geneva, sans-serif; font-size:%s; }\n"
        ".hovout { border: none; padding: 0px; background-color: transparent; color: #0000CE; }\n"
        ".hovin  { border: none; padding: 0px; background-color: transparent; color: #FF0000; }\n"
        "-->\n"
        "</STYLE>\n"
        "<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html;charset=US-ASCII\">\n"
        "<META HTTP-EQUIV=\"Content-Language\" CONTENT=\"en-US\">\n"
        "<META HTTP-EQUIV=\"google\" CONTENT=\"notranslate\">\n"
        "<META NAME=\"viewport\" CONTENT=\"width=device-width\">\n"
        "<LINK REL=\"icon\" TYPE=\"image/gif\" HREF=\"%s%s\">\n"
        "</HEAD>\n"
        "<BODY BGCOLOR=\"#FFFFFF\">\n"
        "<FORM ACTION=\"%s\" METHOD=\"POST\" ENCTYPE=\"multipart/form-data\" %s>\n",
      FONT_SIZE, FONT_SIZE, rt.iconsurl, cfg.favicon, cgiScriptName, /*(rt.js>=2) ? "onsubmit=\"start()\"" :*/ "");




    //
    // TITLE
    //
#ifdef WFM_NOEXPPATH
    fprintf(cgiOut,
            "<!-- TITLE --> \n"
            "<TABLE WIDTH=\"100%%\" BGCOLOR=\"#FFFFFF\" CELLPADDING=\"0\" CELLSPACING=\"0\" BORDER=\"0\" STYLE=\"height:28px;\">\n"
                "<TR>\n"
                "<TD NOWRAP  WIDTH=\"100%%\" BGCOLOR=\"#0072c6\" VALIGN=\"MIDDLE\" ALIGN=\"LEFT\" STYLE=\"color:#FFFFFF; font-weight:bold;\">\n"
                "&nbsp;<IMG SRC=\"%s%s\" ALIGN=\"MIDDLE\" ALT=\"WFM\">\n"
                "%s : %c%s \n"
                "<TD NOWRAP  BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"RIGHT\" STYLE=\"color:#000000; font-weight:bold;  white-space:nowrap\">\n",
            rt.iconsurl, cfg.favicon, cfg.tagline, (strlen(wp.virt_dirname)>0) ? ' ' : '/', wp.virt_dirname
    );
#else
    fprintf(cgiOut,
            "<!-- TITLE --> \n"
            "<TABLE WIDTH=\"100%%\" BGCOLOR=\"#FFFFFF\" CELLPADDING=\"0\" CELLSPACING=\"0\" BORDER=\"0\" STYLE=\"height:28px;\">\n"
                "<TR>\n"
                "<TD NOWRAP  WIDTH=\"100%%\" BGCOLOR=\"#0072c6\" VALIGN=\"MIDDLE\" ALIGN=\"LEFT\" STYLE=\"color:#FFFFFF; font-weight:bold;\">\n"
                "&nbsp;<IMG SRC=\"%s%s\" ALIGN=\"MIDDLE\" ALT=\"WFM\">\n",
            rt.iconsurl, cfg.favicon
    );
    {
        char *p = wp.virt_dirname;
        char *s;
        if( *p == '/') p++;
        fprintf(cgiOut,
             "<A HREF=\"%s?sortby=%s&amp;directory=/&amp;token=%s\">%s</A>/",
            cgiScriptName, sortby, rt.token, cfg.tagline);
        s = p;
        while(1)
        {
            char *tp = strchr( p, '/');
            char *up;
            if( !tp) break;
            p = tp;

            *p = '\0';
            up = url_encode( wp.virt_dirname);
            fprintf(cgiOut,
                 "<A HREF=\"%s?sortby=%s&amp;directory=%s&amp;token=%s\">%s</A>/",
                cgiScriptName, sortby, up, rt.token, s);
            free(up);
            *p = '/';
            p++;
            s = p;
        }
        if( *p)
            fprintf(cgiOut, "%s", s);
    }
    fprintf(cgiOut,
                "\n<TD NOWRAP  BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"RIGHT\" STYLE=\"color:#000000; font-weight:bold;  white-space:nowrap\">\n");
#endif // WFM_NOEXPPATH

    // lock / unlock
    if(!rt.access_as_user && cfg.users_defined)
        fprintf(cgiOut,
            "<A HREF=\"%s?action=login&amp;directory=%s\">"
            "&nbsp;<IMG SRC=\"%s%s.gif\" ALIGN=\"MIDDLE\" BORDER=\"0\" ALT=\"Access\"></A>&nbsp;%s\n",
            cgiScriptName, wp.virt_dirname_urlencoded, rt.iconsurl, access_string[rt.access_level], access_string[rt.access_level]);
    else if(rt.auth_method==3)
        fprintf(cgiOut,
            "<A HREF=\"%s?ea=logoff\">"
            "<IMG SRC=\"%s%s.gif\" BORDER=\"0\" ALIGN=\"MIDDLE\" ALT=\"Access\">"
                "</A>&nbsp;%s&nbsp;<IMG SRC=\"%suser.gif\" ALIGN=\"MIDDLE\" ALT=\"User\">&nbsp;%s&nbsp;\n",
            cgiScriptName, rt.iconsurl, access_string[rt.access_level], access_string[rt.access_level], rt.iconsurl, rt.loggedinuser);

    else
        fprintf(cgiOut,
            "<A HREF=\"%s?directory=%s\"><IMG SRC=\"%s%s.gif\" BORDER=\"0\" ALIGN=\"MIDDLE\" ALT=\"Access\">"
            "</A>&nbsp;%s&nbsp;<IMG SRC=\"%suser.gif\" ALIGN=\"MIDDLE\" ALT=\"User\">&nbsp;%s&nbsp;\n",
            cgiScriptName, wp.virt_dirname_urlencoded, rt.iconsurl, access_string[rt.access_level], access_string[rt.access_level], rt.iconsurl, rt.loggedinuser);

    // about / version
    fprintf(cgiOut,
            "&nbsp;<IMG SRC=\"%snet.gif\" ALIGN=\"MIDDLE\" ALT=\"Client IP\">&nbsp;%s&nbsp;"
            "<A HREF=\"%s?action=about&amp;directory=%s&amp;token=%s\"><IMG BORDER=\"0\" SRC=\"%sver.gif\" ALIGN=\"MIDDLE\" ALT=\"Version\"></A>&nbsp;v%s&nbsp;"
            "</TD>\n"\
            "</TR>\n"\
            "</TABLE>\n",
            rt.iconsurl, cgiRemoteAddr, cgiScriptName, wp.virt_dirname_urlencoded, rt.token, rt.iconsurl, VERSION);



    //
    // TOOLBAR
    //
    fprintf(cgiOut,
            "<!-- TOOLBAR -->\n"\
            "<TABLE WIDTH=\"100%%\" BGCOLOR=\"#FFFFFF\" CELLPADDING=\"0\" CELLSPACING=\"0\" BORDER=\"0\" STYLE=\"height:28px;\">\n"
                "<TR>\n"
                "<!-- DIR-UP -->\n"
                "<TD NOWRAP  BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                 "<A HREF=\"%s?sortby=%s&amp;directory=%s&amp;token=%s\">"
                    "<IMG SRC=\"%sdir_up.gif\" BORDER=0 ALIGN=\"MIDDLE\" WIDTH=\"16\" HEIGHT=\"16\" ALT=\"Dir Up\">&nbsp;Up"
                 "</A>\n"
                "</TD>\n",
                cgiScriptName, sortby, wp.virt_parent_urlencoded, rt.token, rt.iconsurl);

    fprintf(cgiOut,
                "<!-- HOME -->\n"
                "<TD NOWRAP  BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                 "<A HREF=\"%s?sortby=%s&amp;directory=/&amp;token=%s\">"
                    "<IMG SRC=\"%shome.gif\" BORDER=0 ALIGN=\"MIDDLE\" WIDTH=\"16\" HEIGHT=\"16\" ALT=\"Home\">&nbsp;Home"
                 "</A>\n"
                "</TD>\n",
                cgiScriptName, sortby, rt.token, rt.iconsurl);

    fprintf(cgiOut,
                "<!-- RELOAD -->\n"
                "<TD NOWRAP   BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                     "<A HREF=\"%s?sortby=%s&amp;directory=%s&amp;token=%s\">"
                         "<IMG SRC=\"%sreload.gif\" BORDER=0 ALIGN=\"MIDDLE\" ALT=\"Reload\">&nbsp;Refresh"
                     "</A>\n"
                "</TD>\n",
                cgiScriptName, sortby, wp.virt_dirname_urlencoded, rt.token, rt.iconsurl);

    fprintf(cgiOut,
                "<!-- MULTI DELETE -->\n"\
                "<TD NOWRAP   BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                     "<INPUT TYPE=\"IMAGE\" SRC=\"%sdelete.gif\" STYLE=\"border: none; padding: 0px; vertical-align:middle;\" ALT=\"Delete\" ALIGN=\"MIDDLE\" NAME=\"multi_delete_prompt\" VALUE=\"Delete\">\n"
                     "<INPUT TYPE=\"SUBMIT\" CLASS=\"hovout\" NAME=\"multi_delete_prompt\" VALUE=\"Delete\" %s>\n"
                "</TD>\n",
                rt.iconsurl, (rt.js) ? "onMouseOver=\"this.className='hovin';\" onMouseOut=\"this.className='hovout';\"" : "");

    fprintf(cgiOut,
                "<!-- MULTI MOVE -->\n"
                "<TD NOWRAP   BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                     "<INPUT TYPE=\"IMAGE\" SRC=\"%smove.gif\" STYLE=\"border: none; padding: 0px; vertical-align:middle; \" ALT=\"Move\" ALIGN=\"MIDDLE\" NAME=\"multi_move_prompt\" VALUE=\"Move\">\n"
                     "<INPUT TYPE=\"SUBMIT\" CLASS=\"hovout\" NAME=\"multi_move_prompt\" VALUE=\"Move\" %s>\n"
                "</TD>\n",
                rt.iconsurl, (rt.js) ? "onMouseOver=\"this.className='hovin';\" onMouseOut=\"this.className='hovout';\"" : "");

    fprintf(cgiOut,
                "<!-- NEWDIR -->\n"
                "<TD NOWRAP   BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                     "<A HREF=\"%s?action=mkdir_prompt&amp;directory=%s&amp;token=%s\" >\n"
                            "<IMG SRC=\"%smkdir.gif\" BORDER=0 ALIGN=\"MIDDLE\" ALT=\"New Folder\">&nbsp;New Folder\n"
                     "</A>\n"
                "</TD>\n",
                cgiScriptName, wp.virt_dirname_urlencoded, rt.token, rt.iconsurl);


    fprintf(cgiOut,
                "<!-- NEWFILE -->\n"\
                "<TD NOWRAP   BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                     "<A HREF=\"%s?action=mkfile_prompt&amp;directory=%s&amp;token=%s\">"
                            "<IMG SRC=\"%smkfile.gif\" BORDER=0 ALIGN=\"MIDDLE\" ALT=\"New File\">&nbsp;New File"
                     "</A>\n"
                "</TD>\n",
                cgiScriptName, wp.virt_dirname_urlencoded, rt.token, rt.iconsurl);

    fprintf(cgiOut,
                "<!-- NEWURL -->\n"
                "<TD NOWRAP   BGCOLOR=\"#F1F1F1\" VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                     "<A HREF=\"%s?action=mkurl_prompt&amp;directory=%s&amp;token=%s\">"
                            "%s&nbsp;New URL"
                     "</A>\n"
                "</TD>\n",
                cgiScriptName, wp.virt_dirname_urlencoded, rt.token, ICO_LNK);


    fprintf(cgiOut,
                "<!-- UPLOAD -->\n"
                "<TD NOWRAP  BGCOLOR=\"#F1F1F1\"  VALIGN=\"MIDDLE\" ALIGN=\"CENTER\">\n"
                    "<INPUT TYPE=\"hidden\" NAME=\"directory\" VALUE=\"%s\">\n"
                    "<INPUT TYPE=\"hidden\" NAME=\"token\" VALUE=\"%s\">\n"
                    "<INPUT TYPE=\"hidden\" NAME=\"upload_id\" VALUE=\"%d\">\n"
                    "<INPUT TYPE=\"file\" NAME=\"filename\">&nbsp;\n"
                    "<INPUT TYPE=\"submit\" NAME=\"upload\" ID=\"Upload_Status\" VALUE=\"Upload\" %s >\n"
                "</TD>\n"
                "</TR>\n"
            "</TABLE>\n",
            wp.virt_dirname, rt.token, upload_id, (rt.access_level==PERM_RW) ? " " : "DISABLED");

    //
    // SORT BY
    //
    if(strcmp(sortby, "size")==0) {
        snprintf(namepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=name\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Filename</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(sizepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=rsize\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Size</A>&nbsp;%s", cgiScriptName, wp.virt_dirname_urlencoded, rt.token, ICO_ADN);
        snprintf(datepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=date\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Modified</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
    } else if(strcmp(sortby, "rsize")==0) {
        snprintf(namepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=name\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Filename</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(sizepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=size\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Size</A>&nbsp;%s", cgiScriptName, wp.virt_dirname_urlencoded, rt.token, ICO_AUP);
        snprintf(datepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=date\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Modified</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
    } else if(strcmp(sortby, "date")==0) {
        snprintf(namepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=name\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Filename</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(sizepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=size\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Size</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(datepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=rdate\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Modified</A>&nbsp;%s", cgiScriptName, wp.virt_dirname_urlencoded, rt.token, ICO_ADN);
    } else if(strcmp(sortby, "rdate")==0) {
        snprintf(namepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=name\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Filename</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(sizepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=size\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Size</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(datepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=date\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Modified</A>&nbsp;%s", cgiScriptName, wp.virt_dirname_urlencoded, rt.token, ICO_AUP);
    } else if(strcmp(sortby, "name")==0) {
        snprintf(namepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=rname\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Filename</A>&nbsp;%s", cgiScriptName, wp.virt_dirname_urlencoded, rt.token, ICO_ADN);
        snprintf(sizepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=size\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Size</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(datepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=date\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Modified</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
    } else if(strcmp(sortby, "rname")==0) {
        snprintf(namepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=name\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Filename</A>&nbsp;%s", cgiScriptName, wp.virt_dirname_urlencoded, rt.token, ICO_AUP);
        snprintf(sizepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=size\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Size</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(datepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=date\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Modified</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
    } else {
        snprintf(namepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=name\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Filename</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(sizepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=size\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Size</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
        snprintf(datepfx, 1024, "&nbsp;<A HREF=\"%s?directory=%s&amp;token=%s&amp;sortby=date\" STYLE=\"text-decoration: none; color:#FFFFFF;\">Modified</A>", cgiScriptName, wp.virt_dirname_urlencoded, rt.token);
    }


    // SORTBY ROW + dir files display
    fprintf(cgiOut,
            "<!-- MAIN FILE TABLE --> \n"
            "<TABLE WIDTH=\"100%%\" BGCOLOR=\"#FFFFFF\" CELLPADDING=0 CELLSPACING=0 BORDER=0>\n"
            "<!-- SORTBY LINE -->\n"
            "<TR BGCOLOR=\"#FFFFFF\" >\n"
                "<TD NOWRAP  ALIGN=\"left\" WIDTH=\"50%%\" BGCOLOR=\"#A0A0A0\">\n"
                "<FONT COLOR=\"#FFFFFF\">\n");

    if(rt.js) fprintf(cgiOut,
                "<INPUT TYPE=\"CHECKBOX\" NAME=\"CHECKALL\"  STYLE=\"padding: 0px; border: none;\" ONCLICK=\"checkUncheckAll(this, multiselect_filename);\">\n");

    fprintf(cgiOut,
                "%s\n"
                "</FONT>\n"
                "</TD>\n"
                "<TD NOWRAP  ALIGN=\"right\" BGCOLOR=\"#A0A0A0\">\n"
                "<FONT COLOR=\"#FFFFFF\">\n"
                    "%s\n"
                "</FONT>\n"
                "</TD>\n"
                "<TD NOWRAP  ALIGN=\"right\"  BGCOLOR=\"#A0A0A0\">\n"
                "<FONT COLOR=\"#FFFFFF\">\n"
                    "%s\n"
                "</FONT>\n"
                "</TD>\n"
                "<TD NOWRAP  ALIGN=\"right\"  BGCOLOR=\"#A0A0A0\">\n"
                    "&nbsp;"
                "</TD>"
                "<TD NOWRAP  ALIGN=\"left\"  BGCOLOR=\"#A0A0A0\">\n"
                "<FONT COLOR=\"#FFFFFF\">\n"
                    "&nbsp;\n"
                "</FONT>\n"
                "</TD>\n"
            "</TR>\n"
            "<!-- End of Header -->\n\n",
            namepfx, sizepfx, datepfx);

    //
    // Enumerate Directories
    //
    for(e=0; e<nentr; e++) {
        if(!S_ISDIR(direntry[e].type))
            continue;
        if(direntry[e].name[0]=='.') {
            if( !cfg.showdotfiles ||
                (direntry[e].name[1]=='\0') ||
                ((direntry[e].name[1]=='.') && (direntry[e].name[2]=='\0')) )
                    continue;
        }

        name=direntry[e].name;
        name_urlencoded=url_encode(name);

        size=direntry[e].size;

#ifndef WFMSIMPLETIME
        ctime_r(&direntry[e].atime, atime);
        ctime_r(&direntry[e].mtime, mtime);
        ctime_r(&direntry[e].rtime, rtime);

             if(now-direntry[e].mtime < 3600)        stime=M_HR;
        else if(now-direntry[e].mtime < 24*3600)     stime=M_DAY;
        else if(now-direntry[e].mtime < 7*24*3600)   stime=M_WK;
//      else if(now-direntry[e].mtime < 14*24*3600)  stime=M_2WK;
        else if(now-direntry[e].mtime < 31*24*3600)  stime=M_MO;
//      else if(now-direntry[e].mtime < 62*24*3600)  stime=M_2MO;
//      else if(now-direntry[e].mtime < 182*24*3600) stime=M_6MO;
        else if(now-direntry[e].mtime < 365*24*3600) stime=M_YR;
        else                                         stime=M_OLD;
#else
        strftime( atime, sizeof(atime), "%F %T", localtime(&direntry[e].atime));
        strftime( mtime, sizeof(mtime), "%F %T", localtime(&direntry[e].mtime));
        strftime( rtime, sizeof(rtime), "%F %T", localtime(&direntry[e].rtime));
#endif // WFMSIMPLETIME

        if(strcmp(highlight, name)==0)  {
            icon=ICO_NEW;
            linecolor=tHIGH_COLOR;
        }
        else {
            icon=ICO_DIR;
            if(rt.js) {
                linecolor=tNORMAL_COLOR;
            }
            else {
                if(n % 2)
                    linecolor=tNORMAL_COLOR;
                else
                    linecolor=tALTER_COLOR;
            }
        }

        // directory name / date
        fprintf(cgiOut,
            "<!-- Directory Entry -->\n");

        fprintf(cgiOut,
            "<TR BGCOLOR=\"#%s\" ", linecolor);

        if(rt.js)
            fprintf(cgiOut, "onMouseOver=\"this.bgColor='#%s';\" onMouseOut=\"this.bgColor='#%s';\"",
            tHL_COLOR, linecolor);

        fprintf(cgiOut,
            ">\n<TD NOWRAP  ALIGN=\"LEFT\">\n"
            "<INPUT TYPE=\"CHECKBOX\" NAME=\"multiselect_filename\" STYLE=\"border: none;\" VALUE=\"%s\">",
             name);

        fprintf(cgiOut,
            "<A HREF=\"%s?sortby=%s&amp;directory=%s/%s&amp;token=%s\">%s %s</A></TD> \n"
            "<TD NOWRAP  ALIGN=\"RIGHT\">%s</TD>\n"
#ifndef WFMSIMPLETIME
            "<TD NOWRAP  ALIGN=\"RIGHT\"><SPAN TITLE=\"Created:%s\n Modified:%s\n Accessed:%s\n\">%s&nbsp;%s</FONT></SPAN></TD>\n"
#else
            "<TD NOWRAP  ALIGN=\"RIGHT\"><SPAN TITLE=\"Created:%s\n Modified:%s\n Accessed:%s\n\">%s</FONT></SPAN></TD>\n"
#endif
            "<TD NOWRAP >&nbsp;</TD>"
            "<TD NOWRAP  ALIGN=\"LEFT\">",
        cgiScriptName, sortby, (strcmp(wp.virt_dirname, "/")==0) ? "" : wp.virt_dirname_urlencoded, name_urlencoded,  rt.token, icon, name,
#ifndef WFMSIMPLETIME
        buprintf(size, TRUE), rtime, mtime, atime, stime, mtime);
#else
        buprintf(size, TRUE), rtime, mtime, atime, mtime);
#endif

        // rename
        fprintf(cgiOut, "\n"\
            "<A HREF=\"%s?action=rename_prompt&amp;directory=%s&amp;filename=%s&amp;token=%s\" TITLE=\"Rename '%s'\">\n"\
            "<IMG SRC=\"%srename.gif\" BORDER=0 WIDTH=16 HEIGHT=16 ALT=\"Rename File\">\n"\
            "</A>\n",
            cgiScriptName, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, name, rt.iconsurl);

        // move
        fprintf(cgiOut, "\n"\
            "<A HREF=\"%s?action=move_prompt&amp;directory=%s&amp;filename=%s&amp;token=%s\" TITLE=\"Move '%s'\">\n"\
            "<IMG SRC=\"%smove.gif\" BORDER=0 WIDTH=16 HEIGHT=16 ALT=\"Move File\">\n"\
            "</A>\n",
        cgiScriptName, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, name, rt.iconsurl);

        // delete
        fprintf(cgiOut, "\n"\
            "<A HREF=\"%s?action=delete_prompt&amp;directory=%s&amp;filename=%s&amp;token=%s\" TITLE=\"Delete '%s'\">\n"\
            "<IMG SRC=\"%sdelete.gif\" BORDER=0 WIDTH=16 HEIGHT=16 ALT=\"Delete Directory\">\n"\
            "</A>\n"\
            "</TD>\n"\
            "</TR>\n\n\n",
        cgiScriptName, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, name, rt.iconsurl);

        totalsize+=size;
        n++;
    }


    // regular files
    for(e=0; e<nentr; e++) {
        if(S_ISDIR(direntry[e].type))
            continue;
        if(direntry[e].name[0]=='.') {
            if( !cfg.showdotfiles ||
                (direntry[e].name[1]=='\0') ||
                ((direntry[e].name[1]=='.') && (direntry[e].name[2]=='\0')) )
                    continue;
        }

        name=direntry[e].name;
        name_urlencoded=url_encode(name);
        size=direntry[e].size;

#ifndef WFMSIMPLETIME
        ctime_r(&direntry[e].atime, atime);
        ctime_r(&direntry[e].mtime, mtime);
        ctime_r(&direntry[e].rtime, rtime);

             if(now-direntry[e].mtime < 3600)        stime=M_HR;
        else if(now-direntry[e].mtime < 24*3600)     stime=M_DAY;
        else if(now-direntry[e].mtime < 7*24*3600)   stime=M_WK;
//      else if(now-direntry[e].mtime < 14*24*3600)  stime=M_2WK;
        else if(now-direntry[e].mtime < 31*24*3600)  stime=M_MO;
//      else if(now-direntry[e].mtime < 62*24*3600)  stime=M_2MO;
//      else if(now-direntry[e].mtime < 182*24*3600) stime=M_6MO;
        else if(now-direntry[e].mtime < 365*24*3600) stime=M_YR;
        else                                         stime=M_OLD;
#else
        strftime( atime, sizeof(atime), "%F %T", localtime(&direntry[e].atime));
        strftime( mtime, sizeof(mtime), "%F %T", localtime(&direntry[e].mtime));
        strftime( rtime, sizeof(rtime), "%F %T", localtime(&direntry[e].rtime));
#endif // WFMSIMPLETIME

             if(regexec(&reg_zip, name, 0, 0, 0)==0)    { icon=ICO_ZIP; editable=0; is_link=0; }
        else if(regexec(&reg_img, name, 0, 0, 0)==0)    { icon=ICO_IMG; editable=0; is_link=0; }
        else if(regexec(&reg_off, name, 0, 0, 0)==0)    { icon=ICO_OFF; editable=0; is_link=0; }
        else if(regexec(&reg_pdf, name, 0, 0, 0)==0)    { icon=ICO_PDF; editable=0; is_link=0; }
        else if(regexec(&reg_txt, name, 0, 0, 0)==0)    { icon=ICO_TXT; editable=1; is_link=0; }
        else if(regexec(&reg_exe, name, 0, 0, 0)==0)    { icon=ICO_EXE; editable=0; is_link=0; }
        else if(regexec(&reg_med, name, 0, 0, 0)==0)    { icon=ICO_MED; editable=0; is_link=0; }
        else if(regexec(&reg_iso, name, 0, 0, 0)==0)    { icon=ICO_ISO; editable=0; is_link=0; }
        else if(regexec(&reg_lnk, name, 0, 0, 0)==0)    { icon=ICO_LNK; editable=0; is_link=1; }
        else                                            { icon=ICO_GEN; editable=0; is_link=0; }

        if(cfg.edit_any_file)                               { editable=1; }

        if(strcmp(highlight, name)==0)   {
            icon=ICO_NEW;
            linecolor=tHIGH_COLOR;
        }
        else {
            if(rt.js) {
                linecolor=tNORMAL_COLOR;
            }
            else {
                if(n % 2)
                    linecolor=tNORMAL_COLOR;
                else
                    linecolor=tALTER_COLOR;
            }
        }

    // default action
    if(cfg.edit_by_default && editable) {
        action="edit";
        raction="save";
        ricon=ICO_DSK;
        laction="goto_url";
        licon=ICO_LNK;
    } else if(is_link) {
        action="goto_url";
        raction="save";
        ricon=ICO_DSK;
        laction="edit";
        licon=ICO_EDT;
    } else {
        action="save";
        raction="edit";
        ricon=ICO_EDT;
        laction="";
        licon="";
    }

        // filename
        fprintf(cgiOut,
            "<!-- File Entry -->\n");

        fprintf(cgiOut,
            "<TR BGCOLOR=\"#%s\" ", linecolor);

        if(rt.js)
            fprintf(cgiOut, "onMouseOver=\"this.bgColor='#%s';\" onMouseOut=\"this.bgColor='#%s';\"",
            tHL_COLOR, linecolor);

        // default action
        fprintf(cgiOut,
            ">\n<TD NOWRAP  ALIGN=\"LEFT\"><INPUT TYPE=\"CHECKBOX\" NAME=\"multiselect_filename\" STYLE=\"border: none;\" VALUE=\"%s\">"
            "<A HREF=\"%s?action=%s&amp;directory=%s&amp;filename=%s&amp;token=%s\" TITLE=\"%s '%s'\">%s %s</A></TD>\n",
        name, cgiScriptName, action, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, action, name, icon, name);


        // size / date
        fprintf(cgiOut,
            "\n"
            "<TD NOWRAP  ALIGN=\"RIGHT\" >%s</TD>\n"
#ifndef WFMSIMPLETIME
            "<TD NOWRAP  ALIGN=\"RIGHT\" ><SPAN TITLE=\"Created:%s\n Modified:%s\n Accessed:%s\n\">%s&nbsp;%s</FONT></SPAN></TD>\n",
        buprintf(size, TRUE), rtime, mtime, atime, stime, mtime);
#else
            "<TD NOWRAP  ALIGN=\"RIGHT\" ><SPAN TITLE=\"Created:%s\n Modified:%s\n Accessed:%s\n\">%s</FONT></SPAN></TD>\n",
        buprintf(size, TRUE), rtime, mtime, atime, mtime);
#endif

        // file tools
        fprintf(cgiOut, "\n<TD NOWRAP >&nbsp;</TD><TD NOWRAP  ALIGN=\"LEFT\">\n");


        // rename
        fprintf(cgiOut,
            "<A HREF=\"%s?action=rename_prompt&amp;directory=%s&amp;filename=%s&amp;token=%s\" TITLE=\"Rename '%s'\">\n"
            "<IMG SRC=\"%srename.gif\" BORDER=0 WIDTH=16 HEIGHT=16 ALT=\"Rename File\">\n"
            "</A>\n",
            cgiScriptName, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, name, rt.iconsurl);

        // move
        fprintf(cgiOut,
            "\n"
            "<A HREF=\"%s?action=move_prompt&amp;directory=%s&amp;filename=%s&amp;token=%s\" TITLE=\"Move %s\">"
            "<IMG SRC=\"%smove.gif\" BORDER=0 WIDTH=16 HEIGHT=16  ALT=\"Move '%s'\">\n"
            "</A>\n",
            cgiScriptName, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, name,  rt.iconsurl, name);

        // delete
        fprintf(cgiOut,
            "\n"
            "<A HREF=\"%s?action=delete_prompt&amp;directory=%s&amp;filename=%s&amp;token=%s\" "
            "TITLE=\"Remove '%s'\"> \n"
            "<IMG SRC=\"%sdelete.gif\" BORDER=0 WIDTH=16 HEIGHT=16 ALT=\"Delete File\">\n"
            "</A>\n",
            cgiScriptName, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, name, rt.iconsurl);

        // edit for text files..
        if(editable||is_link)
            fprintf(cgiOut,
                "\n"
                "<A HREF=\"%s?action=%s&amp;directory=%s&amp;filename=%s&amp;token=%s\" TITLE=\"%s %s\">\n"
                "%s\n"
                "</A>\n",
            cgiScriptName, raction, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, raction, name, ricon);

        // links
        if(is_link)
            fprintf(cgiOut,
                "\n"
                "<A HREF=\"%s?action=%s&amp;directory=%s&amp;filename=%s&amp;token=%s\" TITLE=\"%s %s\">\n"
                "%s\n"
                "</A>\n",
            cgiScriptName, laction, wp.virt_dirname_urlencoded, name_urlencoded, rt.token, laction, name, licon);

        // view via external link
        if(strlen(cfg.homeurl)>4 && !is_link)
            fprintf(cgiOut,
                "\n"
                "<A HREF=\"%s%s%s/%s\" TITLE=\"Preview '%s' In Browser\">\n"
                "%s\n"
                "</A>\n",
            cfg.homeurl, (wp.virt_dirname[0]!='/') ? "/" : "", (strcmp(wp.virt_dirname, "/")==0) ? "" : wp.virt_dirname, name, name, ICO_LNK);


        fprintf(cgiOut,
            "\n"
            "&nbsp;\n"
            "</TD>\n"
            "</TR>\n\n"
        );

       totalsize+=size;
       n++;
    }

    tstop();

    //
    // footer line
    //
    fprintf(cgiOut,
        "<!-- FOOTER -->\n"
        "<TR>\n"
            "<TD NOWRAP  BGCOLOR=\"#%s\">&nbsp;</TD>\n"
            "<TD NOWRAP  BGCOLOR=\"#%s\" ALIGN=\"right\" STYLE=\"border-top:1px solid grey\">total %s </TD>\n"
            "<TD NOWRAP  BGCOLOR=\"#%s\" ALIGN=\"right\" STYLE=\"color:#D0D0D0;\">%.1f ms</TD>\n"
            "<TD NOWRAP  BGCOLOR=\"#%s\">&nbsp;</TD>\n"
            "<TD NOWRAP  BGCOLOR=\"#%s\">&nbsp;</TD>\n"
        "</TR>\n"
        "</TABLE>\n</FORM>\n</BODY>\n<!-- Page generated in %f seconds -->\n</HTML>\n\n",
        tNORMAL_COLOR, tNORMAL_COLOR, buprintf(totalsize, TRUE), tNORMAL_COLOR, (t2-t1)*1000, tNORMAL_COLOR, tNORMAL_COLOR, t2-t1
    );

}

