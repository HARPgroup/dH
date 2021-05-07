<?php
module_load_include('inc', 'dh', 'plugins/dh.display');
module_load_include('module', 'dh');

  
class dHVarImage extends dHVariablePluginDefault {
  
  public function hiddenFields() {
    return array('pid','featureid','startdate','enddate','propvalue','modified','entity_type', 'dh_link_admin_pr_condition');
  }
  public function formRowEdit(&$rowform, $row) {
    parent::formRowEdit($rowform, $row);
    $varinfo = $row->varid ? dh_vardef_info($row->varid) : FALSE;
    if (!$varinfo) {
      return FALSE;
    }
    $rowform['propcode'] = array(
      '#title' => t($varinfo->varname),
      '#type' => 'textfield',
      '#description' => $varinfo->vardesc,
      '#default_value' => !empty($row->propcode) ? $row->propcode : "",
    );
  }
  
  public function buildContent(&$content, &$entity, $view_mode) {
    parent::buildContent($content, $entity, $view_mode);
    switch ($view_mode) {
      case 'plugin':
      case 'teaser':
      default:
        unset($content['propcode']);
        unset($content['propvalue']);
        $content['image'] = array(  
          '#theme' => 'image_formatter',
          '#item' => array(
            'uri' => $entity->propcode,
          ),
        );
        // @todo: need to use plugin retrieval here, 
        /*
        if (property_exists($entity, 'image_width')) {
          $content['image']['#width'] = $entity->image_width;
        }
        if (property_exists($entity, 'image_height')) {
          $content['image']['#height'] = $entity->image_height;
        }
        */
      break;
    }
  }
}


class dHVarImageField extends dHVariablePluginDefault {
  var $default_bundle = 'image';
  
  public function hiddenFields() {
    return array('pid','featureid','startdate','enddate','propvalue', 'propcode','modified','entity_type', 'dh_link_admin_pr_condition');
  }
  public function formRowEdit(&$rowform, $row) {
    parent::formRowEdit($rowform, $row);
    $varinfo = $row->varid ? dh_vardef_info($row->varid) : FALSE;
    if (!$varinfo) {
      return FALSE;
    }
  }
  
  public function buildContent(&$content, &$entity, $view_mode) {
    parent::buildContent($content, $entity, $view_mode);
    return;
    /*
    switch ($view_mode) {
      case 'plugin':
      case 'teaser':
      default:
        unset($content['propcode']);
        unset($content['propvalue']);
        $content['image'] = array(  
          '#theme' => 'image_formatter',
          '#item' => array(
            'uri' => $entity->propcode,
          ),
        );
        // @todo: need to use plugin retrieval here, 
        //if (property_exists($entity, 'image_width')) {
        //  $content['image']['#width'] = $entity->image_width;
        //}
        //if (property_exists($entity, 'image_height')) {
        //  $content['image']['#height'] = $entity->image_height;
        //}
        
      break;
    }
    */
  }
  public function attachNamedForm(&$form, $entity) {
    $varinfo = $entity->varid ? dh_vardef_info($entity->varid) : FALSE;
    if (!$varinfo) {
      return FALSE;
    }
    // create a blank to house the original form info
    $pform = array();
    $this->formRowEdit($pform, $entity);
    // harvest pieces I want to keep
    $mname = $this->handleFormPropname($entity->propname);
    $form[$mname] = $pform['image'];
    $form[$mname]['#title'] = isset($entity->title) ? t($entity->title) : t($entity->propname);
    $form[$mname]['#description'] = t($entity->vardesc);
  }
  
  public function applyEntityAttribute(&$property, $value) {
    $property->image = $value;
  }
  
  public function getPropertyAttribute($property) {
    return $property->image;
  }
}


class dHVarURL extends dHVarImage {
  
  public function buildContent(&$content, &$entity, $view_mode) {
    parent::buildContent($content, $entity, $view_mode);
    switch ($view_mode) {
      case 'plugin':
      case 'teaser':
      default:
        unset($content['propcode']);
        unset($content['propvalue']);
        $content['link'] = array(  
          '#theme' => 'link',
          '#text' => 'Click Here',
          '#path' => $entity->propcode,
          '#options' => array(
            'attributes' => array(
              'class' => array('first'), 
              //REQUIRED:
              'html' => FALSE,
           ),
        );
      break;
    }
  }
}