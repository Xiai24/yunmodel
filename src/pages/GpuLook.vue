<template>
  <div class="resource-management-container">
    <!-- 视图切换 -->
    <div class="view-tabs">
      <el-button
        v-for="(tab, index) in viewTabs"
        :key="index"
        :class="{ active: currentView === tab.key }"
        @click="currentView = tab.key"
      >
        {{ tab.label }}
      </el-button>
    </div>

    <!-- 地域筛选 -->
    <div class="region-filter">
      <el-button
        v-for="(region, index) in regions"
        :key="index"
        :class="{ active: currentRegion === region.key }"
        @click="currentRegion = region.key"
      >
        {{ region.label }} ({{ region.count }})
      </el-button>
      <el-button type="text" class="expand-btn" @click="showAllRegions = !showAllRegions">
        {{ showAllRegions ? '收起全部' : '展开全部' }}
      </el-button>
      <div class="extra-regions" v-if="showAllRegions">
        <el-button
          v-for="(region, index) in extraRegions"
          :key="index"
          :class="{ active: currentRegion === region.key }"
          @click="currentRegion = region.key"
        >
          {{ region.label }} ({{ region.count }})
        </el-button>
      </div>
    </div>

    <!-- 筛选栏 -->
    <div class="filter-bar">
      <el-select
        v-model="resourceTag"
        placeholder="请选择资源标签"
        class="filter-item"
      >
        <el-option
          v-for="tag in resourceTags"
          :key="tag"
          :label="tag"
          :value="tag"
        />
      </el-select>
      <el-select
        v-model="resourceGroup"
        placeholder="请选择资源组"
        class="filter-item"
      >
        <el-option
          v-for="group in resourceGroups"
          :key="group"
          :label="group"
          :value="group"
        />
      </el-select>
      <el-select
        v-model="productCategory"
        placeholder="请选择产品类目"
        class="filter-item"
      >
        <el-option
          v-for="category in productCategories"
          :key="category"
          :label="category"
          :value="category"
        />
      </el-select>
      <el-select
        v-model="sortType"
        placeholder="推荐排序"
        class="filter-item"
      >
        <el-option
          v-for="(type, index) in sortTypes"
          :key="index"
          :label="type"
          :value="type"
        />
      </el-select>
      <el-switch
        v-model="showAllProducts"
        active-text="查看所有产品"
        inactive-text="仅我的产品"
        class="filter-item"
      />
    </div>

    <!-- 资源列表 -->
    <div class="resource-list">
      <div
        class="resource-category"
        v-for="(category, index) in resourceCategoriesData"
        :key="index"
      >
        <div class="category-header">
          <el-icon :size="20" class="category-icon">
            
          </el-icon>
          <span class="category-title">{{ category.name }}</span>
        </div>
        <div class="product-item" v-for="(product, pIndex) in category.products" :key="pIndex">
          <div class="product-name">
            {{ product.name }}
            <el-icon :size="16" class="arrow-icon">
              <ArrowRight />
            </el-icon>
          </div>
          <div class="product-meta">
            <span v-for="(meta, mIndex) in product.meta" :key="mIndex">
              {{ meta }}
            </span>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import {  ArrowRight } from '@element-plus/icons-vue'

// 视图切换
const viewTabs = ref([
  { label: '产品目录视图', key: 'catalog' },
  { label: '资源列表视图', key: 'list' }
])
const currentView = ref('catalog')

// 地域筛选
const regions = ref([
  { label: '全部', key: 'all', count: 100 },
  { label: '全球', key: 'global', count: 20 },
  { label: '华北2（北京）', key: 'beijing', count: 15 },
  { label: '华东2（上海）', key: 'shanghai', count: 12 },
  { label: '中国香港', key: 'hongkong', count: 8 },
  { label: '日本（东京）', key: 'tokyo', count: 5 }
])
const extraRegions = ref([
  { label: '韩国（首尔）', key: 'seoul', count: 3 },
  { label: '新加坡', key: 'singapore', count: 4 },
  { label: '马来西亚（吉隆坡）', key: 'kuala-lumpur', count: 2 },
  { label: '美国（硅谷）', key: 'silicon-valley', count: 6 },
  { label: '欧洲（法兰克福）', key: 'frankfurt', count: 7 }
])
const currentRegion = ref('all')
const showAllRegions = ref(false)

// 筛选条件
const resourceTags = ref(['标签1', '标签2', '标签3', '标签4'])
const resourceGroups = ref(['资源组A', '资源组B', '资源组C', '资源组D'])
const productCategories = ref(['计算', '存储', '网络', '安全'])
const sortTypes = ref(['推荐排序', '按名称排序', '按数量排序'])
const resourceTag = ref('')
const resourceGroup = ref('')
const productCategory = ref('')
const sortType = ref('推荐排序')
const showAllProducts = ref(false)

// 资源分类数据
const resourceCategoriesData = ref([
  {
    name: '计算',
    products: [
      {
        name: '云服务器 ECS',
        meta: ['50 实例', '20 磁盘', '15 安全组', '30 弹性网卡', '50 自动快照策略', '25 密钥对']
      },
      {
        name: '弹性容器实例 ECI',
        meta: ['30 实例', '10 配置', '20 镜像']
      }
    ]
  },
  {
    name: '存储',
    products: [
      {
        name: '对象存储 OSS',
        meta: ['100 Bucket', '50 图片处理', '30 断点续传']
      },
      {
        name: '文件存储 NAS',
        meta: ['20 文件系统', '10 挂载点', '15 权限组']
      }
    ]
  },
  {
    name: '网络与CDN',
    products: [
      {
        name: '专有网络 VPC',
        meta: ['40 专有网络', '30 交换机', '25 路由表', '20 带宽包']
      },
      {
        name: '内容分发网络 CDN',
        meta: ['50 加速域名', '40 缓存策略', '35 访问控制']
      }
    ]
  },
  {
    name: '域名与网站',
    products: [
      {
        name: '域名',
        meta: ['80 域名', '60 解析记录', '40 ssl证书']
      },
      {
        name: '云解析 DNS',
        meta: ['70 解析器', '50 线路规则', '30 监控']
      }
    ]
  },
  {
    name: '迁移与运维管理',
    products: [
      {
        name: '访问控制 RAM',
        meta: ['60 用户', '40 角色', '30 策略', '20 权限']
      },
      {
        name: '运维编排 OOS',
        meta: ['30 模板', '20 执行记录', '15 自动化任务']
      }
    ]
  }
])
</script>

<style scoped>
.resource-management-container {
  padding: 20px;
  background-color: #f9f9f9;
  min-height: 100vh;
}

/* 视图切换 */
.view-tabs {
  margin-bottom: 20px;
}
.view-tabs .el-button {
  background: #e3f2fd;
  border: 1px solid #bbdefb;
  color: #1565c0;
  margin-right: 10px;
}
.view-tabs .el-button.active {
  background: #1976d2;
  color: #fff;
}

/* 地域筛选 */
.region-filter {
  margin-bottom: 20px;
}
.region-filter .el-button {
  background: #e3f2fd;
  border: 1px solid #bbdefb;
  color: #1565c0;
  margin-right: 10px;
}
.region-filter .el-button.active {
  background: #1976d2;
  color: #fff;
}
.expand-btn {
  color: #1976d2;
}
.extra-regions {
  margin-top: 10px;
}

/* 筛选栏 */
.filter-bar {
  display: flex;
  gap: 20px;
  margin-bottom: 20px;
}
.filter-item {
  width: 200px;
}

/* 资源列表 */
.resource-list {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
  gap: 20px;
}

/* 分类标题 */
.category-header {
  display: flex;
  align-items: center;
  margin-bottom: 10px;
}
.category-icon {
  color: #1976d2;
  margin-right: 10px;
}
.category-title {
  font-size: 16px;
  font-weight: bold;
  color: #333;
}

/* 产品项 */
.product-item {
  background: #fff;
  border: 1px solid #e3f2fd;
  border-radius: 8px;
  padding: 10px;
  margin-bottom: 10px;
}
.product-name {
  font-size: 14px;
  font-weight: bold;
  color: #333;
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.arrow-icon {
  color: #1976d2;
}
.product-meta {
  display: flex;
  flex-wrap: wrap;
  gap: 10px;
  margin-top: 5px;
  color: #666;
}
</style>